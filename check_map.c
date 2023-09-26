/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:18 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:38:18 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_line_content(t_parsing *parsing, int index, int *player_index)
{
	int		i;
	char	*line;

	i = 0;
	line = parsing->map[index];
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == 'S' || line [i] == 'N'
			|| line [i] == 'E' || line [i] == 'W')
		{
			is_invalid_player_position(parsing, i, index);
			(*player_index)++;
		}
		if (line[i] == '0')
		{
			if (is_invalid_zero_position(parsing, index, line, i))
				error_line(parsing);
		}
		else if (is_invalid_map_character(line[i]))
			error_line(parsing);
		i++;
	}
}

void	validate_map_and_player(t_parsing *parsing)
{
	int	i;
	int	player_index;

	i = 0;
	player_index = 0;
	while (parsing->map[i])
	{
		if (i == 0 && contains_zero_character(parsing->map[i]))
			error_line(parsing);
		else
			validate_line_content(parsing, i, &player_index);
		if (player_index > 1)
			error_map(parsing);
		i++;
	}
	if (player_index == 0)
		error_map(parsing);
}
