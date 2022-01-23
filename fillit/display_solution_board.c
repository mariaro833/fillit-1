/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_solution_board.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:27:50 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 16:34:51 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
