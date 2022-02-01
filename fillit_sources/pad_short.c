/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 15:02:41 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	Call just once to calculate only once?
*/

static uint8_t	final_shift(uint8_t board_size)
{
	return (ULONG_BITCOUNT - \
		(board_size * 3 + TETRIMINO_SIZE) % ULONG_BITCOUNT);
}

/*
	calculate total shift before shifting (board_size == 4)
	(uint64_t)(-1) into a #define ERROR
	if statement return with (board_size * 4 % 64) == 0?
		shift becomes 64, which is undefined behaviour...
	break the function into smaller pieces that take responsibility of the
		edge cases 2, 3
	function pointer to three different versions of pad_short
		to reduce the if statements in this function!
*/

uint64_t	pad_short(uint16_t tetrimino, uint8_t board_size)
{
	uint8_t		t;
	uint8_t		tetrimino_line;
	uint64_t	tetrilong;
	int8_t		padding;

	t = TETRIMINO_BITCOUNT;
	if (board_size > TETRIMINO_SIZE)
	{
		padding = (int8_t)board_size - TETRIMINO_SIZE;
		while (t)
		{
			tetrilong <<= TETRIMINO_SIZE;
			t -= TETRIMINO_SIZE;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line);
			tetrilong <<= padding * !!t;
		}
		return (tetrilong << final_shift(board_size));
	}
	else if (board_size == TETRIMINO_SIZE)
		return (((uint64_t)tetrimino) << (64 - TETRIMINO_BITCOUNT));
	else
	{
		padding = (int8_t)board_size - TETRIMINO_SIZE;
		while (t)
		{
			tetrilong <<= TETRIMINO_SIZE;
			t -= TETRIMINO_SIZE;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line);
			tetrilong >>= -padding * !!t;
		}
		return (tetrilong << final_shift(board_size));
	}
}
