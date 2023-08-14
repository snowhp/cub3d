#include "cub3d.h"

void	images_to_xpm(t_mlx *window)
{
	int	height;
	int	weight;

	window->n_img = window->parsing->north_path;
	window->s_img = window->parsing->south_path;
	window->e_img = window->parsing->east_path;
	window->w_img = window->parsing->west_path;
	window->n_xpm = mlx_xpm_file_to_image(window->mlx, window->n_img, &weight, &height);
	window->s_xpm = mlx_xpm_file_to_image(window->mlx, window->s_img, &weight, &height);
	window->e_xpm = mlx_xpm_file_to_image(window->mlx, window->e_img, &weight, &height);
	window->w_xpm = mlx_xpm_file_to_image(window->mlx, window->w_img, &weight, &height);
	if (!window->n_xpm || !window->s_xpm || !window->w_xpm || !window->e_xpm)
	{
		printf ("Erro: Loading Textures\n");
		exit(0);
	}
	window->my_mlx.addr_n = mlx_get_data_addr(window->n_xpm, &window->my_mlx.bpp_n, &window->my_mlx.l_len_n, &window->my_mlx.endian_n);
	window->my_mlx.addr_s = mlx_get_data_addr(window->s_xpm, &window->my_mlx.bpp_s, &window->my_mlx.l_len_s, &window->my_mlx.endian_s);
	window->my_mlx.addr_w = mlx_get_data_addr(window->w_xpm, &window->my_mlx.bpp_w, &window->my_mlx.l_len_w, &window->my_mlx.endian_w);
	window->my_mlx.addr_e = mlx_get_data_addr(window->e_xpm, &window->my_mlx.bpp_e, &window->my_mlx.l_len_e, &window->my_mlx.endian_e);
}