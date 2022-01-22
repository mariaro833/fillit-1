/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/01/21 21:26:16 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ULONG_BITCOUNT 64
#define TETRIMINO_SIZE 4
#define MAX_BOARD_SIZE 20
#define TETRIMINO_BITCOUNT 16

static unsigned char	redundancy_check(unsigned long tetrilong, \
	short shift_modulus)
{
	unsigned long	checker;

	if (shift_modulus < 0)
		shift_modulus = 0;
	checker = tetrilong;
	return ((checker >> shift_modulus) << shift_modulus == tetrilong);
}

/*
	Call just once to calculate only once?
*/

static unsigned char	final_shift(unsigned char board_size)
{
	return (ULONG_BITCOUNT - \
		(board_size * 3 + TETRIMINO_SIZE) % ULONG_BITCOUNT);
}

/*
	calculate total shift before shifting (board_size == 4)
	(unsigned long)(-1) into a #define ERROR
	if statement return with (board_size * 4 % 64) == 0?
		shift becomes 64, which is undefined behaviour...
*/

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_size)
{
	unsigned char	t;
	unsigned char	tetrimino_line;
	unsigned long	tetrilong;
	unsigned char	padding;
	unsigned char	shift_modulus;

	t = TETRIMINO_BITCOUNT;
	tetrilong = 0;
	if (board_size > TETRIMINO_SIZE && board_size <= MAX_BOARD_SIZE)
	{
		padding = board_size - TETRIMINO_SIZE;
		shift_modulus = index % board_size;
		while (t)
		{
			tetrilong <<= TETRIMINO_SIZE;
			t -= TETRIMINO_SIZE;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line) << (padding * !!t);
			if (!redundancy_check(tetrilong, shift_modulus * !!t))
				return ((unsigned long)(-1)); //(~tetrilong); // debug_error("piece doesn't fit the board", -1)
		}
		return (tetrilong << final_shift(board_size));
	}
	else if (board_size == TETRIMINO_SIZE)
		return (((unsigned long)tetrimino) << 48);
	else
		return ((unsigned long)(-1)); //handle gracefully: "error"
}
