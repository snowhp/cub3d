/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/19 15:44:08 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(t_parsing *parsing)
{
	size_t	i;

	i = 0;
	if (parsing->north_path)
		free(parsing->north_path);
	if (parsing->south_path)
		free(parsing->south_path);
	if (parsing->west_path)
		free(parsing->west_path);
	if (parsing->east_path)
		free(parsing->east_path);
	if (parsing->map)
	{
		while (parsing->map[i] != NULL)
			free(parsing->map[i++]);
		free(parsing->map);
	}
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;31mMap Parsing Failed.\033[0m\n");
	exit(1);
}

void	error_line(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (parsing->north_path)
		free(parsing->north_path);
	if (parsing->south_path)
		free(parsing->south_path);
	if (parsing->west_path)
		free(parsing->west_path);
	if (parsing->east_path)
		free(parsing->east_path);
	if (parsing->map)
	{
		while (parsing->map[i] != NULL)
			free(parsing->map[i++]);
		free(parsing->map);
	}
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;35mInvalid Line Format. Please check the format of the line \
		in the map.\033[0m\n");
	exit(1);
}

void	error_color(t_parsing *parsing)
{
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;35mInvalid or missing color value for ceiling or\
		floor.\033[0m\n");
	exit(1);
}
