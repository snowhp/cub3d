/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:26:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/26 10:50:49 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (press == XK_Left)
		rotate_right(window);
	if (press == XK_Right)
		rotate_left(window);
	if (press == XK_D)
		move_right(window);
	if (press == XK_A)
		move_left(window);
	if (press == XK_W)
		move_forward(window);
	if (press == XK_S)
		move_backword(window);
	if (press == XK_Escape)
		destroy_window(window);
	projecting_game(window);
	return (0);
}
