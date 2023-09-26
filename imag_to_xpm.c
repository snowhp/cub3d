/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag_to_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:57 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/26 11:16:28 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	images_to_xpm(t_mlx *w)
{
	int	height;
	int	weight;

	w->north_texture_path = w->parsing->north_path;
	w->south_texture_path = w->parsing->south_path;
	w->east_texture_path = w->parsing->east_path;
	w->west_texture_path = w->parsing->west_path;
	w->n_xpm = mlx_xpm_file_to_image(w->mlx, w->north_texture_path, \
		&weight, &height);
	w->s_xpm = mlx_xpm_file_to_image(w->mlx, w->south_texture_path, \
		&weight, &height);
	w->e_xpm = mlx_xpm_file_to_image(w->mlx, w->east_texture_path, \
		&weight, &height);
	w->w_xpm = mlx_xpm_file_to_image(w->mlx, w->west_texture_path, \
		&weight, &height);
	if (!w->n_xpm || !w->s_xpm || !w->w_xpm || !w->e_xpm)
	{
		printf ("Erro: Loading Textures\n");
		exit(0);
	}
	w->display_data.addr_north = mlx_get_data_addr(w->n_xpm, &w->display_data.\
		bpp_north, &w->display_data.l_len_north, &w->display_data.endian_north);
	w->display_data.addr_south = mlx_get_data_addr(w->s_xpm, &w->display_data.\
	bpp_south, &w->display_data.l_len_south, &w->display_data.endian_south);
	w->display_data.addr_west = mlx_get_data_addr(w->w_xpm, &w->display_data.\
	bpp_west, &w->display_data.l_len_west, &w->display_data.endian_west);
	w->display_data.addr_east = mlx_get_data_addr(w->e_xpm, &w->display_data.\
	bpp_east, &w->display_data.l_len_east, &w->display_data.endian_east);
}

