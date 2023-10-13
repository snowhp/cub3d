/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:14 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/13 09:54:05 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_color_components(char digit, int *comma, int *nbr, int *rgb)
{
	if (digit >= '0' && digit <= '9')
		(*nbr) = (*nbr) * 10 + digit - '0';
	else if (digit == ',')
	{
		if ((*comma) < 3)
			rgb[(*comma)] = *nbr;
		(*comma)++;
		(*nbr) = 0;
	}
	else if (digit != ' ')
	{
		*comma = 0;
		return (0);
	}
	return (1);
}

int	validate_color(char *line)
{
	int	index;
	int	comma;
	int	nbr;
	int	digit[3];

	index = 0;
	comma = 0;
	nbr = 0;
	while (line[index])
	{
		if (update_color_components(line[index], &comma, &nbr, digit) == 0)
			break ;
		index++;
	}
	if (comma == 2 && digit[0] <= 255 && digit[1] <= 255 && nbr <= 255)
		return (((digit[0] << 16) + (digit[1] << 8) + nbr));
	return (-1);
}

int	get_color(char *line, char *str)
{
	char	*keep_color;
	int		color;

	color = -1;
	keep_color = ft_strtrim(line, str);
	if (keep_color[0] != ',' && keep_color[ft_strlen(keep_color) - 1] != ',')
		color = validate_color(keep_color);
	free(line);
	free(keep_color);
	return (color);
}

void	color_values(t_parsing *parsing, char *line, t_index *index)
{
	if (!ft_strncmp(line, "F ", 2))
		parsing->floor_color = get_color(line, " F");
	else if (!ft_strncmp(line, "C ", 2))
		parsing->ceiling_color = get_color(line, " C");
	index->color_count++;
}
