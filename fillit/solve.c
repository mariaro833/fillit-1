/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/25 19:53:23 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
	# include	 <stdio.h>
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

static char	*ft_strnewset(char chr, unsigned long len)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string)
		((char *)ft_memset(string, chr, len + 1))[len] = '\0';
	return (string);
}
/*
	change bitarray to a static function.
*/
/* list of tetriminoes ends with 0UL */
char	*solve(unsigned short *tetriminoes, unsigned char board_size, \
	char depth)
{
	unsigned long			index;
	static unsigned long	bitcount;
	unsigned long			tetrilong;
	char					*string;

	if (!bitcount)
		bitcount = board_size * board_size;
	if (!tetriminoes[(unsigned long)depth])
		return (ft_strnewset('.', bitcount));
	index = 0;
	while (index < bitcount)
	{
		tetrilong = pad_short(tetriminoes[(unsigned long)depth], index, board_size);
		if (tetrilong != (unsigned long)(-1) && bitarrset(bitarray(bitcount, FETCH), index, tetrilong) == 1)
		{
			//printf("tetrimino placed on index %lu\n", index);
			string = solve(tetriminoes, board_size, depth + 1);
			if (string)
			{
				place_alphabet(&string, tetrilong, index, depth + 'A');
				bitcount = 0;
				return (string);
			}
			bitarrunset(bitarray(bitcount, FETCH), index, tetrilong);
			//return (NULL);
		}
		index++;
	}
	if (!depth)
		bitcount = 0;
	return (NULL);
}
