/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:38:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/09/11 15:25:28 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(t_parsing *parsing)
{
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;31mMap Parsing Failed.\033[0m\n");
	exit(1);
}

void	error_line(t_parsing *parsing)
{
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;35mInvalid Line Format. Please check the format of the line \
		in the map.\033[0m\n");
	exit(1);
}

void	error_color(t_parsing *parsing)
{
	free(parsing);
	printf("\033[1;31mError: \033[0m\n");
	printf("\033[1;35mInvalid or missing color value for ceiling or\
		floor.\033[0m\n");
	exit(1);
}
