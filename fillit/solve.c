/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:49:21 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 16:21:53 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	Receives as input the bitarray list of tetrimino shorts
		and smallest possible board_size calculated.
	Solves the smallest possible board.
	Returns the board for displaying in alphabets.
*/

/*
	The board state is stored in bits.
	Bits can only tell if there is a square of a piece in the position,
		and nothing else (no letter).
	Unless constructing the alphabetical board solution can be done,
		the solution is not a solution.
*/

static char *ft_strnewset(char chr, char depth)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (depth + 1));
	if (string)
		ft_memset(string, chr)[depth] = '\0';
	return (string);
}

/* list of tetriminoes ends with 0UL */
char	*solve(unsigned long *tetriminoes, unsigned char board_size, char depth)
{
	unsigned short	index;
	unsigned short	bitcount;
	unsigned long	tetrilong;
	char			*string;

	if (!tetriminoes[depth])
		return (ft_strnewset('.', depth - 1));
	tetrilong = pad_short(tetriminoes[depth], board_size);
	index = 0;
	bitcount = board_size * board_size;
	while (index < bitcount)
	{
		if (bitarrset(bitarray(bitcount, FETCH), tetrilong, index))
		{
			string = solve(tetriminoes, board_size, depth + 1);
			if (string)
				place_alphabet(&string, tetrilong, index, depth + 'A');
			return (string);
		}
		bitarrunset(bitarray(bitcount, FETCH), tetrilong, index);
		index++;
	}
	return (NULL);
}
