/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:07 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 15:26:08 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	north_west(double y_coordinate, double x_coordinate, t_mlx *window)
{
	if ((int)(y_coordinate + 1) % 64 == 0 && window->map[(int)(y_coordinate / \
		64.0) + 1][(int)(x_coordinate / 64.0)] == '0')
	{
		window->ray_position = x_coordinate;
		return ('N');
	}
	else
	{
		window->ray_position = y_coordinate;
		return ('W');
	}
}

char	north_east(double y_coordinate, double x_coordinate, t_mlx *window)
{
	if ((int)(y_coordinate + 1) % 64 == 0 && window->map[(int)((y_coordinate / \
		64.0) + 1)][(int)(x_coordinate / 64.0)] == '0')
	{
		window->ray_position = x_coordinate;
		return ('N');
	}
	else
	{
		window->ray_position = y_coordinate;
		return ('E');
	}
}

char	south_east(double y_coordinate, double x_coordinate, t_mlx *window)
{
	if ((int)(y_coordinate) % 64 == 0 && window->map[(int)((y_coordinate / \
		64.0) - 1)][(int)(x_coordinate / 64.0)] == '0')
	{
		window->ray_position = x_coordinate;
		return ('S');
	}
	else
	{
		window->ray_position = y_coordinate;
		return ('E');
	}
}

char	south_west(double y_coordinate, double x_coordinate, t_mlx *window)
{
	if ((int)(y_coordinate) % 64 == 0 && window->map[(int)((y_coordinate / \
		64.0) - 1)][(int)(x_coordinate / 64.0)] == '0')
	{
		window->ray_position = x_coordinate;
		return ('S');
	}
	else
	{
		window->ray_position = y_coordinate;
		return ('W');
	}
}

char	set_directions(double y_coordinate, double x_coordinate, t_mlx *window)
{
	if (window->y_player > y_coordinate && window->x_player > x_coordinate)
		return (north_west(y_coordinate, x_coordinate, window));
	else if (window->y_player > y_coordinate && window->x_player < x_coordinate)
		return (north_east(y_coordinate, x_coordinate, window));
	else if (window->y_player <= y_coordinate && window->x_player \
		<= x_coordinate)
		return (south_east(y_coordinate, x_coordinate, window));
	else if (window->y_player <= y_coordinate && window->x_player \
		>= x_coordinate)
		return (south_west(y_coordinate, x_coordinate, window));
	return (0);
}
