/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 20:01:28 by thakala          ###   ########.fr       */
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

static char	*solver(t_tetri *tetriminoes, uint8_t board_size, t_bitarr *bitarr)
{
	if (board_size > 4)
		return (solve(tetriminoes, board_size, bitarr, pad_short_gt_4));
	else if (board_size == 4)
		return (solve(tetriminoes, board_size, bitarr, pad_short_eq_4));
	else
		return (solve(tetriminoes, board_size, bitarr, pad_short_lt_4));
}

int	fillit(t_tetri *tetriminoes, uint16_t tetrimino_count)
{
	uint16_t	board_size;
	char		*solution;
	t_bitarr	*bitarr;

	board_size = min_board(tetrimino_count * 4);
	solution = NULL;
	while (1)
	{
		final_shift((uint8_t)board_size, TOGGLE);
		bitarr = bitarray(board_size * board_size, UPDATE);
		if (!bitarr)
			return ((int) errors("bitarray malloc error", 3));
		solution = solver(tetriminoes, (uint8_t)board_size, bitarr);
		if (solution)
			break ;
		board_size++;
	}
	display_solution_board(solution, board_size);
	free(solution);
	bitarrfree(&bitarr);
	return (0);
}
