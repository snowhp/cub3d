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
    printf("North Image Path: %s\n", window->n_img);
    printf("South Image Path: %s\n", window->s_img);
    printf("East Image Path: %s\n", window->e_img);
    printf("West Image Path: %s\n", window->w_img);
    printf("North XPM: %p\n", window->n_xpm);
    printf("South XPM: %p\n", window->s_xpm);
    printf("East XPM: %p\n", window->e_xpm);
    printf("West XPM: %p\n", window->w_xpm);
    printf("Addr_n: %p\n", window->my_mlx.addr_n);
    printf("Addr_s: %p\n", window->my_mlx.addr_s);
    printf("Addr_w: %p\n", window->my_mlx.addr_w);
    printf("Addr_e: %p\n", window->my_mlx.addr_e);
}

//tester player position

void print_player_info(const t_mlx *window) 
{
	printf("===== Player Info =====\n");
    printf("Player Position: (%f, %f)\n", window->y_player, window->x_player);
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
		window.window = mlx_new_window(window.mlx, WIN_W, WIN_H, "Cub3D");
		images_to_xpm(&window);
		print_mlx_info(&window);//tester
		get_player_position(&window);
		print_player_info(&window);//tester
		free(parsing);
    }
	else
		printf("The number of Arguments need to be 2\n");
}