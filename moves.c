#include "cub3d.h"

void	move_right(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	y_step = sin((window->player_view + 90) * M_PI / 180) * PIXELS_PER_MOVE;
	x_step = cos((window->player_view + 90) * M_PI / 180) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player + y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player + x_step) / WALL_HEIGHT;
	if (window->map[y_map][x_map] == '0' && window->map[(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player += x_step;
		window->y_player += y_step;
	}
}
void	move_left(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	x_step = cos((window->player_view + 90) * (M_PI / 180)) * PIXELS_PER_MOVE;
	y_step = sin((window->player_view + 90) * (M_PI / 180)) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player - y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player - x_step) / WALL_HEIGHT;
	if (window->map[y_map][x_map] == '0' && window->map[(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player -= x_step;
		window->y_player -= y_step;
	}
}

void	move_forward(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	y_step = sin(window->player_view * M_PI / 180) * (PIXELS_PER_MOVE);
	x_step = cos(window->player_view * M_PI / 180) * (PIXELS_PER_MOVE);
	y_map = (int)(window->y_player + y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player + x_step) / WALL_HEIGHT;
	if (window->map[y_map][x_map] == '0' && window->map[(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player += x_step;
		window->y_player += y_step;
	}
}

void	move_backword(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	y_step = sin(window->player_view * M_PI / 180) * PIXELS_PER_MOVE;
	x_step = cos(window->player_view * M_PI / 180) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player - y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player - x_step) / WALL_HEIGHT;
	if (window->map[y_map][x_map] == '0' && window->map[(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player -= x_step;
		window->y_player -= y_step;
	}
}
