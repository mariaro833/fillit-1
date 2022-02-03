/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_current_solution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:49:23 by thakala           #+#    #+#             */
/*   Updated: 2022/02/03 13:56:53 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_current_board(t_bitarr *bitarr, t_tetri *tetriminoes, \
	uint8_t board_size)
{
	char		*board_state;
	uint64_t	tetrilong;
	uint16_t	index;
	uint8_t		hashes;

	board_state = ft_strnewset('.', (uint16_t)(bitarr->len + 1));
	board_state[bitarr->len] = '\0';
	if (board_size > 4)
		tetrilong = pad_short_gt_4(tetriminoes->shape, board_size);
	else if (board_size == 4)
		tetrilong = pad_short_eq_4(tetriminoes->shape, board_size);
	else
		tetrilong = pad_short_lt_4(tetriminoes->shape, board_size);
	while (tetriminoes->shape)
	{
		hashes = 0;
		index = (!tetriminoes->row + tetriminoes->row - 1) \
			* board_size + tetriminoes->col;
		while (hashes < HASH_COUNT)
		{
			if (board_state[index] == '.')
			{
				if (tetrilong & (1ULL << (ULONG_BITCOUNT - index % ULONG_BITCOUNT - 1)))
				{
					board_state[index] = (char)(tetriminoes->depth + 'A');
					hashes++;
				}
			}
			else
				break ;
			index++;
		}
		tetriminoes++;
	}
	display_solution_board(board_state, board_size);
	free(board_state);
}

void	display_current_board_depth(t_bitarr *bitarr, t_tetri *tetriminoes, \
	uint8_t board_size, uint8_t recursion_depth)
{
	char		*board_state;
	uint64_t	tetrilong;
	uint16_t	index;
	uint8_t		tetrilong_index;
	uint8_t		hashes;

	board_state = ft_strnewset('.', (uint16_t)(bitarr->len + 1));
	board_state[bitarr->len] = '\0';
	tetriminoes -= recursion_depth;
	while (tetriminoes->depth <= recursion_depth && tetriminoes->shape)
	{
		if (board_size > 4)
			tetrilong = pad_short_gt_4(tetriminoes->shape, board_size);
		else if (board_size == 4)
			tetrilong = pad_short_eq_4(tetriminoes->shape, board_size);
		else
			tetrilong = pad_short_lt_4(tetriminoes->shape, board_size);
		hashes = 0;
		index = tetriminoes->row * board_size + tetriminoes->col;
		tetrilong_index = 0;
		while (hashes < HASH_COUNT)
		{
			if (tetrilong & (1ULL << (ULONG_BITCOUNT - tetrilong_index % ULONG_BITCOUNT - 1)))
			{
				board_state[index] = (char)(tetriminoes->depth + 'A');
				hashes++;
			}
			tetrilong_index++;
			index++;
		}
		tetriminoes++;
	}
	display_solution_board(board_state, board_size);
	ft_putstr("\n");
	free(board_state);
}
