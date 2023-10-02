/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:26:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/02 14:25:57 by tde-sous         ###   ########.fr       */
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

int	release_keys(int press, t_mlx *window)
{
	if (press == XK_Left)
		window->rot_l = 0;
	if (press == XK_Right)
		window->rot_r = 0;
	if (press == 100)
		window->right = 0;
	if (press == 97)
		window->left = 0;
	if (press == 119)
		window->up = 0;
	if (press == 115)
		window->down = 0;
	if (press == XK_Escape)
		destroy_window(window);
	return (0);
}

int	get_keys(int press, t_mlx *window)
{
	if (press == XK_Left)
		window->rot_l = 1;
	if (press == XK_Right)
		window->rot_r = 1;
	if (press == 100)
		window->right = 1;
	if (press == 97)
		window->left = 1;
	if (press == 119)
		window->up = 1;
	if (press == 115)
		window->down = 1;
	if (press == XK_Escape)
		destroy_window(window);
	return (0);
}
