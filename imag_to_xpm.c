/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag_to_xpm .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:57 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/13 10:58:42 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_imageload(t_mlx *window, char *path)
{
	void	*imagep;
	int		size;

	size = 40;
	imagep = mlx_xpm_file_to_image(window->mlx, path, &size, &size);
	return (imagep);
}

void	images_to_xpm_aux(t_mlx *w)
{
	w->display_data.addr_north = mlx_get_data_addr(w->n_xpm, &w->display_data.\
		bpp_north, &w->display_data.l_len_north, &w->display_data.endian_north);
	w->display_data.addr_south = mlx_get_data_addr(w->s_xpm, &w->display_data.\
	bpp_south, &w->display_data.l_len_south, &w->display_data.endian_south);
	w->display_data.addr_west = mlx_get_data_addr(w->w_xpm, &w->display_data.\
	bpp_west, &w->display_data.l_len_west, &w->display_data.endian_west);
	w->display_data.addr_east = mlx_get_data_addr(w->e_xpm, &w->display_data.\
	bpp_east, &w->display_data.l_len_east, &w->display_data.endian_east);
	w->tile = ft_imageload(w, "sprites/dirt.xpm");
	w->tree = ft_imageload(w, "sprites/tree.xpm");
	w->north_char = ft_imageload(w, "sprites/North.xpm");
	w->south_char = ft_imageload(w, "sprites/South.xpm");
	w->east_char = ft_imageload(w, "sprites/East.xpm");
	w->west_char = ft_imageload(w, "sprites/West.xpm");
}

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
	images_to_xpm_aux(w);
}
