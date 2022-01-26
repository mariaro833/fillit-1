/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_alphabet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:21:45 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 15:14:31 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	# include	 <stdio.h>
#include "fillit.h"

/*
	Shift left one-by-one until four bits of 1 are encountered.
	Once a bit of 1 is encountered place the alphabet in the string
		at the correct index.
	Index variable points to a position in the board and in the string.
*/

void	place_alphabet(char *answer, uint64_t tetrilong, \
	uint64_t index, char alphabet)
{
	uint8_t	c;
//	uint8_t	i;

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
}



/*
void	place_alphabet(char *answer, uint64_t tetrilong, \
	uint64_t index, char alphabet)
{
	(void)answer;
	(void)tetrilong;
	(void)index;
	(void)alphabet;
printf("index: %lu tetrimino: %c\n", index, alphabet);
}*/
