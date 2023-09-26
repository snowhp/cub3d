/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:42 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:55:58 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_invalid_zero_position(t_parsing *parsing, int index, char *line, int i)
{
	if (i >= (int)(ft_strlen(parsing->map[index + 1])) ||
			(parsing->map[index + 1] == 0 ||
			index - 1 < 0 || line[i - 1] == ' ' ||
			line[i + 1] == ' ' || line[i + 1] == '\0'
			|| parsing->map[index - 1][i] == ' ' ||
			parsing->map[index + 1][i] == '\0' ||
			parsing->map[index + 1][i] == ' '))
	{
		return (1);
	}
	return (0);
}

void	is_invalid_player_position(t_parsing *parsing, int i, int index)
{
	if (parsing->map[index + 1] == 0
		|| index - 1 < 0
		|| parsing->map[index][i - 1] == ' ' ||
		parsing->map[index][i + 1] == ' ' ||
		parsing->map[index][i + 1] == '\0' ||
		parsing->map[index - 1][i] == ' '
		|| parsing->map[index + 1][i] == '\0' ||
		parsing->map[index + 1][i] == ' ')
	{
		error_line(parsing);
	}
}
