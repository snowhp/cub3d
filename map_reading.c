/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:52 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:57:26 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//tester
/*void print_index_info(t_index *index) {
    printf("===== t_index =====\n");
    printf("texture_count: %d\n", index->texture_count);
    printf("color_count:   %d\n", index->color_count);
    printf("map_index:    %d\n", index->map_index);
    //printf("new_line:      %d\n", index->new_line);
    printf("===== End of t_index =====\n");
}*/

void	process_map_line(t_parsing *parsing, t_index *index, char *line)
{
	if (parsing->north_path == 0 || parsing->south_path == 0
		|| parsing->west_path == 0 || parsing->east_path == 0)
	{
		printf("\033[0;33mError: Missing texture path at line %d\033[0m\n",\
			index->texture_count);
		exit(0);
	}
	if (parsing->ceiling_color == -1
		|| parsing->floor_color == -1 || index->color_count != 2)
		error_color(parsing);
	parsing -> map[index->map_index] = ft_strdup(line);
	index -> map_index++;
}

void	get_info_map(t_parsing *parsing,
		char *line, t_index *index, int *texture_nbr)
{
	char		*aux;

	aux = ft_strtrim(line, " ");
	if (is_texture_line(aux))
		assign_texture_path(parsing, aux, texture_nbr, index);
	else if (!ft_strncmp(aux, "F ", 2) || !ft_strncmp(aux, "C ", 2))
		color_values(parsing, aux, index);
	else if ((aux[0] == '1' || aux[0] == '0' || index->map_index != 0))
	{
		if (aux[0] == '1' || aux[0] == '0' )
			process_map_line(parsing, index, line);
		free(aux);
		aux = 0;
	}
	else
		free(aux);
	free(line);
}

void	read_map(char *file, t_parsing *parsing)
{
	char	*lines;
	int		fd;
	char	*aux;
	int		textures_nbr;
	t_index	number;

	textures_nbr = 0;
	lines = 0;
	initialize_index(&number);
	fd = open(file, O_RDONLY);
	while (1)
	{
		lines = get_next_line(fd);
		aux = lines;
		if (lines == 0)
			break ;
		if (lines[0] == '\n' && number.map_index != 0)
			error_map(parsing);
		lines = ft_strtrim(lines, "\n");
		get_info_map(parsing, lines, &number, &textures_nbr);
		free(aux);
	}
	//print_index_info(&number);//tester
	parsing->map[number.map_index] = 0;
	validate_map_and_player(parsing);
}
