/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:04:36 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/04 12:06:43 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_minimap(t_mlx *window)
{
	int	x;
	int	y;

	if (window->x_player / 64 - 5 < 0)
		x = 0;
	else
		x = window->x_player / 64 - 3;

	if (window->y_player / 64 - 5 < 0)
		y = 0;
	else
		y = window->y_player / 64 - 3;

	int	print_x;
	int	print_y;
	int	printed_x;
	int	printed_y;

	print_x = x;
	print_y = y;
	printed_x = 0;
	printed_y = 0;

	while (window->map[print_y] && print_y < y + 6)
	{
		print_x = x;
		printed_x = 0;
		while (window->map[print_y][print_x] && print_x < x + 6)
		{
			if (window->map[print_y][print_x] == '1')
				mlx_put_image_to_window(window->mlx, window->window, window->tree, 40 * printed_x, 40 * printed_y);
			else if (print_y == (int)window->y_player / 64 && print_x == (int)window->x_player / 64)
			{
				if ((int)window->player_view >= 135 && (int)window->player_view < 225)
					mlx_put_image_to_window(window->mlx, window->window, window->west_char, 40 * printed_x, 40 * printed_y);
				else if ((int)window->player_view >= 315 || (int)window->player_view < 45)
					mlx_put_image_to_window(window->mlx, window->window, window->east_char, 40 * printed_x, 40 * printed_y);
				else if ((int)window->player_view >= 225 && (int)window->player_view < 315)
					mlx_put_image_to_window(window->mlx, window->window, window->north_char, 40 * printed_x, 40 * printed_y);
				else if ((int)window->player_view >= 45 && (int)window->player_view < 135)
					mlx_put_image_to_window(window->mlx, window->window, window->south_char, 40 * printed_x, 40 * printed_y);
			}
			else if (window->map[print_y][print_x] == '0')
				mlx_put_image_to_window(window->mlx, window->window, window->tile, 40 * printed_x, 40 * printed_y);
			print_x++;
			printed_x++;
		}
		print_y++;
		printed_y++;
	}
}
