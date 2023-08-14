#include "cub3d.h"

void	point_of_view(t_mlx *window, char direction)
{
	if (direction == 'N')
		window->field_of_view = 90.0;
	else if (direction == 'S')
		window->field_of_view = 270.00;
	else if (direction == 'E')
		window->field_of_view = 360.0;
	else if (direction == 'W')
		window->field_of_view = 180.0;
}

void	get_player_position(t_mlx *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'N' || window->map[i][j] == 'S' || window->map[i][j] == 'W' || window->map[i][j] == 'E')
			{
				point_of_view(window, window->map[i][j]);
				window->map[i][j] = '0';
				window->y_player = i * 64;
				window->x_player = j * 64;
				break ;
			}
			j++;
		}
		i++;
	}
}