#include "cub3d.h"

//tester
/*void print_map(t_parsing *parsing) 
{
	int i = 0;
	printf("===== Map =====\n");
	while (i < parsing->number_lines) 
	{
		printf("%s\n", parsing->map[i]);
		i++;
	}
	printf("===== End of Map =====\n");
}
*/

//tester struct

void print_mlx_info(const t_mlx *window) 
{
	printf("===== t_mlx =====\n");
    printf("North Image Path: %s\n", window->north_texture_path);
    printf("South Image Path: %s\n", window->south_texture_path);
    printf("East Image Path: %s\n", window->east_texture_path);
    printf("West Image Path: %s\n", window->west_texture_path);
    printf("North XPM: %p\n", window->n_xpm);
    printf("South XPM: %p\n", window->s_xpm);
    printf("East XPM: %p\n", window->e_xpm);
    printf("West XPM: %p\n", window->w_xpm);
    printf("Addr_n: %p\n", window->display_data.addr_north);
    printf("Addr_s: %p\n", window->display_data.addr_south);
    printf("Addr_w: %p\n", window->display_data.addr_west);
    printf("Addr_e: %p\n", window->display_data.addr_east);
}

//tester player position

void print_player_info(const t_mlx *window) 
{
	printf("===== Player Info =====\n");
    printf("Player Position: (%f, %f)\n", window->y_player, window->x_player);
}

//tester rendering
void test_rendering(t_mlx *window) 
{
	printf("==========RENDERING================\n");
    printf("Testing rendering functions...\n");

    // Store original values of relevant variables
    double original_player_view = window->player_view;
    double original_ray_distance = window->ray_distance;
    char original_player_direction = window->player_direction;

    // Call the functions you want to test
    projecting_game(window);

    // Print updated values of relevant variables
    printf("Player view after projecting_game: %.2f\n", window->player_view);
    printf("Ray distance after projecting_game: %.2f\n", window->ray_distance);
    printf("Player direction after projecting_game: %c\n", window->player_direction);

    // Restore original values to test the next function
    window->player_view = original_player_view;
    window->ray_distance = original_ray_distance;
    window->player_direction = original_player_direction;

    // Call the next function
    // calculate_Ray_Intersections(window, ...);

    // Print updated values of relevant variables
    // printf("Player view after calculate_Ray_Intersections: %.2f\n", window->player_view);
    // ...

    // Restore original values to test the last function
    // window->player_view = original_player_view;
    // ...

    // Call the last function
    // render_3d_view(...);

    // Print updated values of relevant variables
    // printf("Player view after render_3d_view: %.2f\n", window->player_view);
    // ...

    printf("Testing completed!\n");
}


int	main(int argc, char **argv)
{
	t_parsing	*parsing;
	t_mlx		window;

	if (argc == 2)
	{
		parsing = malloc(sizeof(t_parsing));
		if (parsing == NULL) 
		{
            printf("Memory allocation failed");
        }
		parse_cub_file(argc, argv, parsing);
		//print_map(parsing);//tester
		window.parsing = parsing;
		window.map = parsing->map;
		window.mlx = mlx_init();
		window.window = mlx_new_window(window.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
		images_to_xpm(&window);
		print_mlx_info(&window);//tester
		get_player_position(&window);
		print_player_info(&window);//tester
		projecting_game(&window);
		test_rendering(&window);//tester
		mlx_hook(window.window, 2, 0, get_keys, &window);
		//mlx_hook(wind.window, 17, 0, destroy_window, &window);
		mlx_loop(&window);
		free(parsing);
    }
	else
		printf("The number of Arguments need to be 2\n");
}