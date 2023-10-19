/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:36:53 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/19 15:37:07 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path_check(char *line, char *ser)
{
	char	*path;
	char	*tmp;
	int		fd;

	tmp = line;
	path = ft_strtrim(line, ser);
	free(tmp);
	line = ft_strtrim(path, " ");
	free(path);
	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		printf("\033[1;33mERROR: Could not open texture.\033[0m\n");
		free(line);
		exit(0);
	}
	close(fd);
	return (line);
}

void	assign_texture_path(t_parsing *parsing, char *line, int *n, t_index *i)
{
	if (*n > 3)
	{
		free(line);
		printf("\033[1;31mERROR: Exceded maximum number"
			"of textures allowed.\033[0m\n");
		exit(0);
	}
	if (!ft_strncmp(line, "SO ", 3))
		parsing->south_path = get_path_check(line, "SO");
	else if (!ft_strncmp(line, "NO ", 3))
		parsing->north_path = get_path_check(line, "NO");
	else if (!ft_strncmp(line, "WE ", 3))
		parsing->west_path = get_path_check(line, "WE");
	else if (!ft_strncmp(line, "EA ", 3))
		parsing->east_path = get_path_check(line, "EA");
	else
	{
		free(line);
		return ;
	}
	(*n)++;
	i->texture_count = (*n);
}
