/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/16 13:19:01 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;
	int		yy_map;
	int		xx_map;

	y_step = sin((window->player_view + 90) * M_PI / 180) * PIXELS_PER_MOVE;
	x_step = cos((window->player_view + 90) * M_PI / 180) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player + y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player + x_step) / WALL_HEIGHT;
	yy_map = (int)(window->y_player + (y_step * 5)) / WALL_HEIGHT;
	xx_map = (int)(window->x_player + (x_step * 5)) / WALL_HEIGHT;
	if (window->map[yy_map][xx_map] == '1')
		return ;
	printf("x_step = %f y_step = %f \n",  x_step, y_step);
	if (window->map[y_map][x_map] == '0' && window->map[(int) \
		(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player += x_step;
		window->y_player += y_step;
	}
	printf("X:%f Y:%f\n", window->x_player, window->y_player);
}

void	move_left(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;
	int		yy_map;
	int		xx_map;

	x_step = cos((window->player_view + 90) * (M_PI / 180)) * PIXELS_PER_MOVE;
	y_step = sin((window->player_view + 90) * (M_PI / 180)) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player - y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player - x_step) / WALL_HEIGHT;
	yy_map = (int)(window->y_player - (y_step * 5)) / WALL_HEIGHT;
	xx_map = (int)(window->x_player - (x_step * 5)) / WALL_HEIGHT;
	if (window->map[yy_map][xx_map] == '1')
		return ;
	if (window->map[y_map][x_map] == '0' && window->map[(int) \
		(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player -= x_step;
		window->y_player -= y_step;
	}
	printf("X:%f Y:%f\n", window->x_player, window->y_player);
}

void	move_forward(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;
	int		yy_map;
	int		xx_map;

	y_step = sin(window->player_view * M_PI / 180) * (PIXELS_PER_MOVE);
	x_step = cos(window->player_view * M_PI / 180) * (PIXELS_PER_MOVE);
	y_map = (int)(window->y_player + y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player + x_step) / WALL_HEIGHT;
	yy_map = (int)(window->y_player + (y_step * 7)) / WALL_HEIGHT;
	xx_map = (int)(window->x_player + (x_step * 7)) / WALL_HEIGHT;
	if (window->map[yy_map][xx_map] == '1')
		return ;
	if (window->map[y_map][x_map] == '0' && window->map[\
		(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player += x_step;
		window->y_player += y_step;
	}
	printf("X:%f Y:%f\n", window->x_player, window->y_player);
}

void	move_backward(t_mlx *window)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;
	int		yy_map;
	int		xx_map;

	y_step = sin(window->player_view * M_PI / 180) * PIXELS_PER_MOVE;
	x_step = cos(window->player_view * M_PI / 180) * PIXELS_PER_MOVE;
	y_map = (int)(window->y_player - y_step) / WALL_HEIGHT;
	x_map = (int)(window->x_player - x_step) / WALL_HEIGHT;
	yy_map = (int)(window->y_player - (y_step * 7)) / WALL_HEIGHT;
	xx_map = (int)(window->x_player - (x_step * 7)) / WALL_HEIGHT;
	if (window->map[yy_map][xx_map] == '1')
		return ;
	if (window->map[y_map][x_map] == '0' && window->map[\
		(int)(window->y_player / WALL_HEIGHT)][x_map] == '0')
	{
		window->x_player -= x_step;
		window->y_player -= y_step;
	}
	printf("X:%f Y:%f\n", window->x_player, window->y_player);
}

void	move_player(t_mlx *window)
{
	if (window->rot_l == 1)
		rotate_left(window);
	if (window->rot_r == 1)
		rotate_right(window);
	if (window->right == 1)
		move_right(window);
	if (window->left == 1)
		move_left(window);
	if (window->up == 1)
		move_forward(window);
	if (window->down == 1)
		move_backward(window);
}
