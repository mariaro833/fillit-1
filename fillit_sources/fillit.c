/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 20:19:01 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
	# include	<unistd.h>
	# include	"../eval_tests/eval_tests.h"

void	display_bitarray(t_bitarr *bitarr, unsigned long board_size)
{
	unsigned long	c;
	unsigned long	bitcount;
	unsigned long	n;
	unsigned long	height;
	unsigned char	first;

	c = 0;
	bitcount = 0;
	height = 0;
	while (bitcount < bitarr->size)
	{
		first = 1;
		while (bitcount % ULONG_BITCOUNT || first)
		{
			n = bitarr->arr[c] >> (ULONG_BITCOUNT - bitcount % ULONG_BITCOUNT - 1);
			first = 0;
			if (n & 1)
				write(1, "1", 1);
			else if (height < board_size)
				write(1, "0", 1);
			else
				write(1, "-", 1);
			if (height < board_size && bitcount % board_size == board_size - 1)
			{
				write(1, "\n", 1);
				height++;
			}
			bitcount++;
		}
		c++;
	}
	write(1, "\n\n", 2);
}

static uint16_t	min_board(t_tetri *tetriminoes, uint16_t square_count)
{
	uint16_t	result;

	result = 2;
	while (result * result < square_count)
		result++;
	if (result == 2 && tetriminoes->shape != O_0)
		result += 1 + (tetriminoes->width == 4 || tetriminoes->height == 4);
	else if (result == 3)
		if (tetriminoes->width == 4 || tetriminoes++->height == 4 \
			|| tetriminoes->width == 4 || tetriminoes->height == 4)
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

	board_size = min_board(tetriminoes, tetrimino_count * 4);
	solution = NULL;
	while (1)
	{
		final_shift((uint8_t)board_size, TOGGLE);
		bitarr = bitarray(board_size * board_size, UPDATE);
		display_bitarray(bitarr, board_size);
		display_current_board(bitarr, tetriminoes, (uint8_t)board_size);
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
