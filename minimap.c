/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:04:36 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/13 11:03:48 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_mlx *window, t_minimap *minimap)
{
	minimap->x = 0;
	minimap->y = 0;
	minimap->print_x = 0;
	minimap->print_y = 0;
	minimap->printed_x = 0;
	minimap->printed_y = 0;
	if (window->x_player / 64 - 5 < 0)
		minimap->x = 0;
	else
		minimap->x = window->x_player / 64 - 3;
	if (window->y_player / 64 - 5 < 0)
		minimap->y = 0;
	else
		minimap->y = window->y_player / 64 - 3;
	minimap->print_x = minimap->x;
	minimap->print_y = minimap->y;
	minimap->printed_x = 0;
	minimap->printed_y = 0;
}

void	put_image_minimap(t_mlx *window, t_minimap *m)
{
	if (window->map[m->print_y][m->print_x] == '1')
		mlx_put_image_to_window(window->mlx, window->window, window->tree, 40 \
			* m->printed_x, 40 * m->printed_y);
	else if (m->print_y == (int)window->y_player / 64 && m->print_x == \
		(int)window->x_player / 64)
	{
		if ((int)window->player_view >= 135 && (int)window->player_view < 225)
			mlx_put_image_to_window(window->mlx, window->window, \
				window->west_char, 40 * m->printed_x, 40 * m->printed_y);
		else if ((int)window->player_view >= 315 || \
			(int)window->player_view < 45)
			mlx_put_image_to_window(window->mlx, window->window, \
				window->east_char, 40 * m->printed_x, 40 * m->printed_y);
		else if ((int)window->player_view >= 225 && (\
			int)window->player_view < 315)
			mlx_put_image_to_window(window->mlx, window->window, \
				window->north_char, 40 * m->printed_x, 40 * m->printed_y);
		else if ((int)window->player_view >= 45 && \
			(int)window->player_view < 135)
			mlx_put_image_to_window(window->mlx, window->window, \
				window->south_char, 40 * m->printed_x, 40 * m->printed_y);
	}
	else if (window->map[m->print_y][m->print_x] == '0')
		mlx_put_image_to_window(window->mlx, window->window, \
			window->tile, 40 * m->printed_x, 40 * m->printed_y);
}

void	put_minimap(t_mlx *window)
{
	t_minimap	m;

	init_struct(window, &m);
	while (window->map[m.print_y] && m.print_y < m.y + 6)
	{
		m.print_x = m.x;
		m.printed_x = 0;
		while (window->map[m.print_y][m.print_x] && m.print_x < m.x + 6)
		{
			put_image_minimap(window, &m);
			m.print_x++;
			m.printed_x++;
		}
		m.print_y++;
		m.printed_y++;
	}
}
