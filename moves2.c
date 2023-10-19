/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves 2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/19 15:28:13 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_detector(t_mlx *window, int minus, double y_step, double x_step)
{
	int		yy_map;
	int		xx_map;

	if (minus == 1)
	{
		yy_map = (int)(window->y_player - (y_step * 7)) / WALL_HEIGHT;
		xx_map = (int)(window->x_player - (x_step * 7)) / WALL_HEIGHT;
	}
	else
	{
		yy_map = (int)(window->y_player + (y_step * 7)) / WALL_HEIGHT;
		xx_map = (int)(window->x_player + (x_step * 7)) / WALL_HEIGHT;
	}
	if (window->map[yy_map][xx_map] == '1')
		return (1);
	return (0);
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
