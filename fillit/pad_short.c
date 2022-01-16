/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/01/16 19:06:26 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ULONG_BITCOUNT 64
#define TETRIMINO_SIZE 4

static unsigned char	total_shift(unsigned short index, \
	unsigned char board_width)
{
	return ((board_width * TETRIMINO_SIZE) % ULONG_BITCOUNT \
		- index % ULONG_BITCOUNT);
}

/*
	calculate total shift before shifting (board_width == 4)
*/

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_width)
{
	unsigned char	t;
	unsigned char	tetrimino_line;
	unsigned long	tetrilong;
	unsigned char	padding;

	t = 16;
	if (board_width > 4 && board_width <= 20)
	{
		padding = board_width - 4;
		while (t)
		{
			tetrilong <<= 4;
			t -= 4;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line) << padding;
		}
		return (tetrilong << total_shift(index, board_width));
	}
	else if (board_width == 4)
		return ((((unsigned long)tetrimino) << 48) >> index % 64);
	else
		return ((unsigned long)(-1));
}
