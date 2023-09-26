/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempCodeRunnerFile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:36:47 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 14:45:02 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_parsing	*parsing;

	if (argc == 2)
	{
		parsing = malloc(sizeof(t_parsing));
		if (parsing == NULL)
			printf("Memory allocation failed");
		parse_cub_file(argc, argv, parsing);
		print_map(parsing);//tester
		free(parsing);
	}
	else
		printf("The number of Arguments need to be 2\n");
}
