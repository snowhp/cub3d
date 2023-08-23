#include "cub3d.h"

void	images_to_xpm(t_mlx *window)
{
	int	height;
	int	weight;

	window->north_texture_path = window->parsing->north_path;
	window->south_texture_path = window->parsing->south_path;
	window->east_texture_path = window->parsing->east_path;
	window->west_texture_path = window->parsing->west_path;
	window->n_xpm = mlx_xpm_file_to_image(window->mlx, window->north_texture_path, &weight, &height);
	window->s_xpm = mlx_xpm_file_to_image(window->mlx, window->south_texture_path, &weight, &height);
	window->e_xpm = mlx_xpm_file_to_image(window->mlx, window->east_texture_path, &weight, &height);
	window->w_xpm = mlx_xpm_file_to_image(window->mlx, window->west_texture_path, &weight, &height);
	if (!window->n_xpm || !window->s_xpm || !window->w_xpm || !window->e_xpm)
	{
		printf ("Erro: Loading Textures\n");
		exit(0);
	}
	window->display_data.addr_north = mlx_get_data_addr(window->n_xpm, &window->display_data.bpp_north, &window->display_data.l_len_north, &window->display_data.endian_north);
	window->display_data.addr_south = mlx_get_data_addr(window->s_xpm, &window->display_data.bpp_south, &window->display_data.l_len_south, &window->display_data.endian_south);
	window->display_data.addr_west = mlx_get_data_addr(window->w_xpm, &window->display_data.bpp_west, &window->display_data.l_len_west, &window->display_data.endian_west);
	window->display_data.addr_east = mlx_get_data_addr(window->e_xpm, &window->display_data.bpp_east, &window->display_data.l_len_east, &window->display_data.endian_east);
}