/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 14:53:20 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint16_t	min_board(uint16_t square_count)
{
	uint16_t	result;

	result = 2;
	while (result * result < square_count)
		result++;
	return (result);
}

int	fillit(t_tetri *tetriminoes, uint16_t tetrimino_count)
{
	uint16_t	board_size;
	char		*solution;
	t_bitarr	*bitarr;

	board_size = min_board(tetrimino_count * 4);
	solution = (char *)0;
	while (1)
	{
		bitarr = bitarray(board_size * board_size, UPDATE);
		// bitarray failure?
		solution = solve(tetriminoes, board_size, bitarr);
		if (solution)
			break ;
		board_size++;
	}
	display_solution_board(solution, board_size);
	free(solution);
	//bitarrfree?
	return (0);
}
