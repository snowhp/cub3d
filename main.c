/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:55:32 by tde-sous          #+#    #+#             */
/*   Updated: 2023/10/19 15:18:35 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_mlx *window)
{
	move_player(window);
	mlx_destroy_image(window->mlx, window->display_data.img);
	window->display_data.img = mlx_new_image(window->mlx, S_WIDTH, S_HEIGHT);
	window->display_data.addr = mlx_get_data_addr(window->display_data.img, \
		&window->display_data.bits_per_pixel, &window->display_data.line_size, \
		&window->display_data.endian);
	projecting_game(window);
	return (0);
}

void	load_extra(t_mlx *window)
{
	window->up = 0;
	window->down = 0;
	window->left = 0;
	window->right = 0;
	window->rot_r = 0;
	window->rot_l = 0;
	window->display_data.img = mlx_new_image(window->mlx, S_WIDTH, S_HEIGHT);
	window->display_data.addr = mlx_get_data_addr(window->display_data.img, \
		&window->display_data.bits_per_pixel, &window->display_data.line_size, \
		&window->display_data.endian);
}

void	parsing_initializer(t_parsing	*parsing)
{
	parsing->north_path = NULL;
	parsing->south_path = NULL;
	parsing->west_path = NULL;
	parsing->east_path = NULL;
	parsing->map = NULL;
	if (parsing == NULL)
		printf("Memory allocation failed");
}

int	main(int argc, char **argv)
{
	t_parsing	*parsing;
	t_mlx		window;

	if (argc == 2)
	{
		parsing = malloc(sizeof(t_parsing));
		parsing_initializer(parsing);
		parse_cub_file(argc, argv, parsing);
		window.parsing = parsing;
		window.map = parsing->map;
		window.mlx = mlx_init();
		window.window = mlx_new_window(window.mlx, S_WIDTH, S_HEIGHT, "Cub3D");
		images_to_xpm(&window);
		get_player_position(&window);
		load_extra(&window);
		projecting_game(&window);
		hooks(&window);
		free(parsing);
	}
	else
		printf("The number of Arguments need to be 2\n");
}
