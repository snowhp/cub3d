/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:54 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:58:00 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_parsing(t_parsing *parsing)
{
	parsing->north_path = 0;
	parsing->south_path = 0;
	parsing->east_path = 0;
	parsing->west_path = 0;
	parsing->ceiling_color = -1;
	parsing->floor_color = -1;
	parsing->map = 0;
	parsing->number_lines = 0;
}

void	initialize_index(t_index *number)
{
	number->map_index = 0;
	number->color_count = 0;
	number->texture_count = 0;
	//number->new_line = 0;
}
