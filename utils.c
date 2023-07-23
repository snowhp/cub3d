#include "cub3d.h"

int	contains_zero_character(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	is_invalid_map_character(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'S'
		&& c != 'N' && c != 'E' && c != 'W')
		return (1);
	return (0);
}

int	is_texture_line(char *line )
{
	if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
	{
		return (1);
	}
	return (0);
}