/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/01/31 14:04:04 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	unnecessary shift_modulus < 0 check?
*/

static uint8_t	redundancy_check(uint64_t tetrilong, uint8_t shift_modulus)
{
	if (shift_modulus < 0)
		shift_modulus = 0;
	return ((tetrilong >> shift_modulus) << shift_modulus == tetrilong);
}

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
*/

uint64_t	pad_short(uint16_t tetrimino, uint64_t index, uint8_t board_size)
{
	uint8_t		t;
	uint8_t		tetrimino_line;
	uint64_t	tetrilong;
	char		padding;
	uint8_t		shift_modulus;

	t = TETRIMINO_BITCOUNT;
	tetrilong = 0;
	if (board_size >= TETRIMINO_SIZE - 2 && board_size <= MAX_BOARD_SIZE)
	{
		padding = (int8_t)board_size - TETRIMINO_SIZE;
		shift_modulus = index % board_size;
		while (t)
		{
			tetrilong <<= TETRIMINO_SIZE;
			t -= TETRIMINO_SIZE;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line);
			if (padding >= 0)
				tetrilong <<= padding * !!t;
			else if (redundancy_check(tetrilong, (uint8_t)(-padding)))
				tetrilong >>= -padding * !!t;
			else
				return ((uint64_t)(-1));
			if (padding >= 0 && !redundancy_check(tetrilong, shift_modulus * !!t))
				return ((uint64_t)(-1)); //(~tetrilong); // debug_error("piece doesn't fit the board", -1)
		}
		return (tetrilong << final_shift(board_size));
	}
	else if (board_size == TETRIMINO_SIZE)
		return (((uint64_t)tetrimino) << 48);
	else
		return ((uint64_t)(-1)); //handle gracefully: "error"
}
