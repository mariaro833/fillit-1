/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 17:53:10 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	Sort the tetrimino_reference list and use binary search on it.
*/

static int	fillit(int fd)
{
	unsigned short	*tetriminoes;
	unsigned long	tetrimino_count;
	unsigned long	board_size;
	char			*solution;

	tetrimino_reference((unsigned short []){I_0, I_1, J_0, J_1, J_2, J_3, L_0, \
		L_1, L_2, L_3, O_0, S_0, S_1, T_0, T_1, T_2, T_3, Z_0, Z_1}, SET);
	tetriminoes = get_tetriminoes(fd, &tetrimino_count);
	board_size = min_board(tetrimino_count);
	solution = (char *)0;
	while (!solution)
	{
		bitarray(board_size * board_size, UPDATE);
		solution = solve(tetriminoes, board_size++, 0);
	}
	display_solution_board(solution);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (errors("argument count mismatch", -1));
	fd = open_input(*(++argv));
	if (fd == -1)
		return (error());
	return (fillit(fd));
}
