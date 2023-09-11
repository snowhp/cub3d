#include "cub3d.h"

void	rotate_left(t_mlx *window)
{
	window->player_view -= ROTATION_ANGLE_INCREMENT;
	if (window->player_view > 360.0)
		window->player_view = 0;
	if (window->player_view < 0)
		window->player_view = 360.0;
}

void	rotate_right(t_mlx *window)
{
	window->player_view += ROTATION_ANGLE_INCREMENT;
	if (window->player_view > 360.0)
		window->player_view = 0;
	if (window->player_view < 0)
		window->player_view = 360.0;
}

int	get_keys(int press, t_mlx *window)
{
	mlx_clear_window(window->mlx, window->window);
	printf("Key detected ");
	if (press == 124)
		rotate_right(window);
	if (press == 123)
		rotate_left(window);
	if (press == 2 || press == D)
		move_right(window);
	if (press == 0 || press == A)
		move_left(window);
	if (press == 13 || press == W)
		move_forward(window);
	if (press == 1 || press == S)
	{
		printf("S");
		move_backword(window);
	}
	if (press == 65307)
		destroy_window(window);
	projecting_game(window);
	return (0);
}
