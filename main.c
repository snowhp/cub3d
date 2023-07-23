#include "cub3d.h"

//tester
void print_map(t_parsing *parsing) 
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

int	main(int argc, char **argv)
{
	t_parsing	*parsing;

	if (argc == 2)
	{
		parsing = malloc(sizeof(t_parsing));
		if (parsing == NULL) 
		{
            printf("Memory allocation failed");
        }
		parse_cub_file(argc, argv, parsing);
		print_map(parsing);//tester
		free(parsing);
    }
	else
		printf("The number of Arguments need to be 2\n");
}