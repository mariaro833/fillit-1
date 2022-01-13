/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:51:26 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 10:52:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	pad_short(short tetrimino, unsigned long index, \
	unsigned char board_width)
{
	unsigned char	t;
	unsigned char	tetrimino_line;
	unsigned long	tetrilong;
	unsigned char	padding;

	t = 16;
	if (board_width > 4)
	{
		padding = board_width - 4;
		while (t)
		{
			t -= 4;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong << (index + 16 - t)) ^ tetrimino_line;
			tetrilong = tetrilong << padding;
		}
		return ();
	}
	else
		return (debug_error());
}