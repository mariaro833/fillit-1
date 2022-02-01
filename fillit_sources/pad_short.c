/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 20:10:18 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	final_shift(uint8_t board_size, uint8_t flag)
{
	static uint8_t	shift;

	if (flag & TOGGLE)
		return (shift = ULONG_BITCOUNT - \
			(board_size * 3 + TETRIMINO_SIZE) % ULONG_BITCOUNT);
	return (shift);
}

uint64_t	pad_short_gt_4(uint16_t tetrimino, uint8_t board_size)
{
	uint8_t		t;
	uint8_t		tetrimino_line;
	uint64_t	tetrilong;
	int8_t		padding;

	t = TETRIMINO_BITCOUNT;
	padding = (int8_t)board_size - TETRIMINO_SIZE;
	while (t)
	{
		tetrilong <<= TETRIMINO_SIZE;
		t -= TETRIMINO_SIZE;
		tetrimino_line = (tetrimino >> t) & 0b1111;
		tetrilong = (tetrilong ^ tetrimino_line);
		tetrilong <<= padding * !!t;
	}
	return (tetrilong << final_shift(0, 0));
}

uint64_t	pad_short_eq_4(uint16_t tetrimino, uint8_t board_size)
{
	(void)board_size;
	return (((uint64_t)tetrimino) << (64 - TETRIMINO_BITCOUNT));
}

uint64_t	pad_short_lt_4(uint16_t tetrimino, uint8_t board_size)
{
	uint8_t		t;
	uint8_t		tetrimino_line;
	uint64_t	tetrilong;
	int8_t		padding;

	t = TETRIMINO_BITCOUNT;
	padding = (int8_t)board_size - TETRIMINO_SIZE;
	while (t)
	{
		tetrilong <<= TETRIMINO_SIZE;
		t -= TETRIMINO_SIZE;
		tetrimino_line = (tetrimino >> t) & 0b1111;
		tetrilong = (tetrilong ^ tetrimino_line);
		tetrilong >>= -padding * !!t;
	}
	return (tetrilong << final_shift(0, 0));
}
