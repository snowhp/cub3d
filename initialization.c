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

