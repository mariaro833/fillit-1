/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:27:50 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 12:08:05 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_solution_board(char *solution, unsigned long board_size)
{
	unsigned long	height;

	height = 0;
	while (height < board_size)
	{
		write(1, solution + (height++) * board_size, board_size);
		write(1, "\n", 1);
	}
}

/*
** 	message				output			comments
**	error					-1		tetriminoes error;
** 	mallocation issues 		0
**	reader error			2
**	open error				2
*/

long	errors(char *message, long output)
{
	ft_putstr (message);
	tetrimino_reference(NULL, FREE);
	return (output);
}
