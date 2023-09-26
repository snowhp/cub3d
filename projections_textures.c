/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:11 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:48:24 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*north_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->ray_position);
	if (mlx->projection_3d > S_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - S_HEIGHT) / 2.0) \
				* (1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->display_data.addr_north + \
		(y * mlx->display_data.l_len_north + (x * 4));
	return (mlx->color);
}

char	*south_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->ray_position);
	if (mlx->projection_3d > S_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - S_HEIGHT) / 2.0) * \
			(1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->display_data.addr_south + \
		(y * mlx->display_data.l_len_south + (x * 4));
	return (mlx->color);
}

char	*east_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->ray_position);
	if (mlx->projection_3d > S_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - S_HEIGHT) / 2.0) * \
			(1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->display_data.addr_east + \
		(y * mlx->display_data.l_len_east + (x * 4));
	return (mlx->color);
}

char	*west_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->ray_position);
	if (mlx->projection_3d > S_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - S_HEIGHT) / 2.0) * \
			(1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->display_data.addr_west + \
		(y * mlx->display_data.l_len_west + (x * 4));
	return (mlx->color);
}
