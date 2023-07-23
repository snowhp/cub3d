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
		exit(0);
	}
	close(fd);
	return (line);
}

void	assign_texture_path(t_parsing *parsing, char *line, int *number, t_index *index )
{
	if (*number > 3)
	{
		free(line);
		printf("\033[1;31mERROR: Exceded maximum number of textures allowed.\033[0m\n");
		exit(0);
	}
	//printf("Texture1 %d: %s\n", *number, line);
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
	(*number)++;
	index->texture_count = (*number);
	//printf("number of textures: %d\n", index->texture_count);
}