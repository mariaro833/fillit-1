/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_alphabet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:21:45 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 15:08:49 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	Shift left one-by-one until four bits of 1 are encountered.
	Once a bit of 1 is encountered place the alphabet in the string
		at the correct index.
	Index variable points to a position in the board and in the string.
*/

char	*place_alphabet(char *answer, uint64_t tetrilong, \
	uint64_t index, t_tetri *tetrimino)
{
	char	alphabet;
	uint8_t	c;

	alphabet = (char)tetrimino->depth + 'A';
	c = 0;
	while (c < HASH_COUNT)
	{
		if ((tetrilong & (1UL << 63)))
		{
			answer[index] = alphabet;
			c++;
		}
		index++;
		tetrilong <<= 1;
	}
	return (answer);
}
