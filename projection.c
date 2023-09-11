/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:52:55 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	projecting_game(t_mlx *window)
{
	double	angle;

	window->height = -1;
	angle = window->player_view - HALF_WALL_HEIGHT;
	window->display_data.img = mlx_new_image(window->mlx, S_WIDTH, S_HEIGHT);
	window->display_data.addr = mlx_get_data_addr(window->display_data.img, \
		&window->display_data.bits_per_pixel, &window->display_data.line_size, \
		&window->display_data.endian);
	while (++window->height < S_WIDTH)
	{
		calculate_ray_intersections(window, angle, window->height);
		angle += WALL_HEIGHT / S_WIDTH;
	}
	mlx_put_image_to_window(window->mlx, window->window, \
		window->display_data.img, 0, 0);
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

void	calculate_ray_intersections(t_mlx *w, double angle, int x)
{
	double	px;
	double	py;

	w->player_direction = '\0';
	px = w->x_player;
	py = w->y_player;
	w->x_step = cos((angle) * (M_PI / 180));
	w->y_step = sin((angle) * (M_PI / 180));
	while (1)
	{
		w->y_m = (int)(py / WALL_HEIGHT);
		w->x_m = (int)(px / WALL_HEIGHT);
		if (w->map[w->y_m][w->x_m] == '1' || w->map[(int)(((py - w->y_step) \
			/ 64))][w->x_m] == '1' || w->map[w->y_m][(int)(((px - w->x_step) \
			/ 64))] == '1')
		{
			w->ray_distance = distance_view(w->y_player, w->x_player, py, px);
			w->player_direction = set_directions(py, px, w);
			w->ray_position = (int)(w->ray_position * (1000.0 / 64.0)) % 1000;
			break ;
		}
		px += w->x_step;
		py += w->y_step;
	}
	render_3d_view(correct_distance(w, angle), x, w, w->player_direction);
}

void	render_3d_view(double distance, int height, t_mlx *mlx, char playerdir)
{
	int	i;

	i = -1;
	mlx->width = 0;
	mlx->distance_to_projection = ((S_WIDTH / 2.0) / (tan((HALF_WALL_HEIGHT) \
		* (M_PI / 180))));
	mlx->projection_3d = (WALL_HEIGHT / distance) * mlx->distance_to_projection;
	mlx->floor_ceiling_origin = (S_HEIGHT / 2) - (mlx->projection_3d / 2);
	while (mlx->width < S_HEIGHT && mlx->width < mlx->floor_ceiling_origin)
	{
		set_pixel_color(&mlx->display_data, height, mlx->width++, \
			mlx->parsing->ceiling_color);
	}
	while (mlx->width < S_HEIGHT && mlx->width < mlx->floor_ceiling_origin + \
		mlx->projection_3d && ++i < S_HEIGHT)
	{
		draw_textures(mlx, i, playerdir);
		mlx->width++;
	}
	while (mlx->width < S_HEIGHT)
	{
		set_pixel_color(&mlx->display_data, height, mlx->width ++, \
			mlx->parsing->floor_color);
	}
}
