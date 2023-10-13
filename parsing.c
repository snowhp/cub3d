/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:45 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/13 11:29:40 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//testers!!!!

void	print_parsing_info(t_parsing *parsing)
{
	printf("===== t_parsing =====\n");
	printf("north_path:    %s\n", parsing->north_path);
	printf("south_path:    %s\n", parsing->south_path);
	printf("west_path:     %s\n", parsing->west_path);
	printf("east_path:     %s\n", parsing->east_path);
	printf("ceiling_color: %d\n", parsing->ceiling_color);
	printf("floor_color:   %d\n", parsing->floor_color);
	printf("number_lines:  %d\n", parsing->number_lines);
	printf("===== End of t_parsing =====\n");
}

//final testers!!

void	check_file_extension(char **argv)
{
	int	size;

	size = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + size, 5) != 0)
	{
		ft_putstr_fd(" Error: the file needs to end with .cub ", 2);
		exit(1);
	}
}

int	validate_arguments(char **argv, int argc)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	check_file_extension(argv);
	if (argc != 2)
	{
		ft_putstr_fd(" <error arrgument> \n", 2);
		exit(1);
	}
	return (fd);
}

int	count_file_lines(int fd)
{
	char	*line;
	int		lines_nbr;

	lines_nbr = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			close(fd);
			break ;
		}
		free(line);
		lines_nbr++;
	}
	if (lines_nbr == 0)
	{
		printf("error file");
		exit(1);
	}
	return (lines_nbr);
}

void	parse_cub_file(int argc, char **argv, t_parsing *parsing)
{
	int	lines_nbr;

	lines_nbr = 0;
	initialize_parsing(parsing);
	lines_nbr = count_file_lines(validate_arguments(argv, argc));
	parsing->map = malloc(lines_nbr * sizeof(char *));
	if (parsing->map == NULL)
	{
		printf("Memory allocation failed in parse_cub_file");
		exit(1);
	}
	parsing->number_lines = lines_nbr;
	read_map(argv[1], parsing);
}
