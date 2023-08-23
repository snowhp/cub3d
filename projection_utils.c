
#include "cub3d.h"

double	distance_view(double y_player, double x_player, double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall)) + ((y_player - y_wall) * (y_player - y_wall))));
}

double	correct_distance(t_mlx *mlx, double angle)
{
	mlx->corrected_distance = mlx->ray_distance * cos((angle - mlx->player_view) * (M_PI / 180));
	return (mlx->corrected_distance);
}

void	set_pixel_color(t_texture_data *data, int x, int y, int color)
{
	char	*pixel_address;

	pixel_address = data->addr + (y * data->line_size + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel_address = color ;
}