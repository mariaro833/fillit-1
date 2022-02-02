/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_current_solution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:49:23 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 17:12:28 by thakala          ###   ########.fr       */
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

	board_state = ft_strnewset('.', bitarr->len + 1);
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
		index = (tetriminoes->row - 1) * board_size + tetriminoes->col;
		while (hashes < HASH_COUNT)
		{
			if (board_state[index] == '.')
			{
				if (tetrilong & (1U << (ULONG_BITCOUNT - index % ULONG_BITCOUNT)))
				{
						board_state[index] = tetriminoes->depth + 'A';
					hashes++;
				}
			}
			else
				break ;
			index++;
		}
		tetriminoes++;
	}
	ft_putstr(board_state);
	free(board_state);
}

