/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/01/17 17:19:23 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ULONG_BITCOUNT 64
#define TETRIMINO_SIZE 4

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
	calculate total shift before shifting (board_size == 4)
	(unsigned long)(-1) into a #define ERROR
	if statement return with (board_size * 4 % 64) == 0?
		shift becomes 64, which is undefined behaviour...
*/

// !! overrun detection not working from including board_size 6

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_size)
{
	unsigned char	t;
	unsigned char	tetrimino_line;
	unsigned long	tetrilong;
	unsigned char	padding;
	unsigned char	shift_modulus;

	t = 16;
	tetrilong = 0;
	if (board_size > 4 && board_size <= 20)
	{
		padding = board_size - 4;
		shift_modulus = index % board_size;
		while (t)
		{
			tetrilong <<= 4;
			t -= 4;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line) << padding;
			if (!redundancy_check(tetrilong, shift_modulus))
				return (~tetrilong);//(unsigned long)(-1));
		}
		if (redundancy_check(tetrilong, index % 64 - board_size))
			return (tetrilong << (64 - board_size * 4 % 64));
		else
			return (~(tetrilong << (64 - board_size * 4 % 64)));//(unsigned long)(-1));
	}
	else if (board_size == 4)
		return ((((unsigned long)tetrimino) << 48) >> index % board_size);
	else
		return ((unsigned long)(-1));
}
