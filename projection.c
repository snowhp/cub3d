#include "cub3d.h"

void	projecting_game(t_mlx *window)
{
	double	angle;

	window->height = -1;
	angle = window->player_view - HALF_WALL_HEIGHT;
	window->display_data.img = mlx_new_image(window->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	window->display_data.addr = mlx_get_data_addr(window->display_data.img, &window->display_data.bits_per_pixel, &window->display_data.line_size, &window->display_data.endian);
	while (++window->height < SCREEN_WIDTH)
	{
		calculate_Ray_Intersections(window, angle, window->height);
		angle += WALL_HEIGHT / SCREEN_WIDTH;
	}
	mlx_put_image_to_window(window->mlx, window->window, window->display_data.img, 0, 0);
}

void	draw_textures(t_mlx *mlx, int i, char player_diretion)
{
	if (player_diretion == 'N')
		set_pixel_color(&mlx->display_data, mlx->height, mlx->width,
			*(unsigned int *)north_texture(mlx, i));
	else if (player_diretion == 'S')
		set_pixel_color(&mlx->display_data, mlx->height, mlx->width,
			*(unsigned int *)south_texture(mlx, i));
	else if (player_diretion == 'W')
		set_pixel_color(&mlx->display_data, mlx->height, mlx->width,
			*(unsigned int *)west_texture(mlx, i));
	else if (player_diretion == 'E')
		set_pixel_color(&mlx->display_data, mlx->height, mlx->width,
			*(unsigned int *)east_texture(mlx, i));
}

void	calculate_Ray_Intersections(t_mlx *window, double angle, int x)
{
	double	px;
	double	py;

	window->player_direction = '\0';
	px = window->x_player;
	py = window->y_player;
	window->x_step = cos((angle) * (M_PI / 180));
	window->y_step = sin((angle) * (M_PI / 180));
	while (1)
	{
		window->y_m = (int)(py / WALL_HEIGHT);
		window->x_m = (int)(px / WALL_HEIGHT);
		if (window->map[window->y_m][window->x_m] == '1' || window->map[(int)(((py - window->y_step) / 64))][window->x_m] == '1' || window->map[window->y_m][(int)(((px - window->x_step) / 64))] == '1')
		{
			window->ray_distance = distance_view(window->y_player, window->x_player, py, px);
			window->player_direction = set_directions(py, px, window);
			window->ray_position = (int)(window->ray_position * (1000.0 / 64.0)) % 1000;
			break ;
		}
		px += window->x_step;
		py += window->y_step;
	}
	render_3d_view(correct_distance(window, angle), x, window, window->player_direction);
}

void	render_3d_view(double distance, int height, t_mlx *mlx, char player_diretion)
{
	int	i;

	i = -1;
	mlx->width = 0;
	mlx->distance_to_projection = ((SCREEN_WIDTH / 2.0) / (tan((HALF_WALL_HEIGHT) * (M_PI / 180))));
	mlx->projection_3d = (WALL_HEIGHT / distance) * mlx->distance_to_projection;
	mlx->floor_ceiling_origin = (SCREEN_HEIGHT / 2) - (mlx->projection_3d / 2);
	while (mlx->width < SCREEN_HEIGHT && mlx->width < mlx->floor_ceiling_origin)
	{
		set_pixel_color(&mlx->display_data, height, mlx->width++, mlx->parsing->ceiling_color);
	}
	while (mlx->width < SCREEN_HEIGHT && mlx->width < mlx->floor_ceiling_origin + mlx->projection_3d && ++i < SCREEN_HEIGHT)
	{
		draw_textures(mlx, i, player_diretion);
		mlx->width++;
	}
	while (mlx->width < SCREEN_HEIGHT)
	{
		set_pixel_color(&mlx->display_data, height, mlx->width ++, mlx->parsing->floor_color);
	}
}