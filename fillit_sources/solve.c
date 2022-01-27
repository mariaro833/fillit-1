/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/27 08:40:26 by thakala          ###   ########.fr       */
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

static char	*ft_strnewset(char chr, uint16_t len)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string)
		((char *)ft_memset(string, chr, len + 1))[len] = '\0';
	return (string);
}

uint8_t	skip_index(uint16_t *index, t_tetri *tetrimino, uint16_t board_size)
{
	if (*index % board_size > board_size - tetrimino->width)
		*index += tetrimino->width - 1;
	return (*index / board_size > board_size - tetrimino->height);
}

/*
	change bitarray to a static function.
*/
/* list of tetriminoes ends with 0UL */

/* tetriminoes[(uint64_t)depth] too big cast? */

char	*solve(t_tetri *tetriminoes, uint16_t board_size, char depth)
{
	static uint16_t	bitcount;
	uint16_t		index;
	uint64_t		tetrilong;
	char			*answer;
	//static t_bitarr	*bitarr;

	if (!bitcount)
		bitcount = board_size * board_size;
	if (!tetriminoes[(uint64_t)depth].shape)
		return (ft_strnewset('.', bitcount));
	index = 0;
	tetrilong = pad_short(tetriminoes[(uint64_t)depth].shape, index, (uint8_t)board_size);
	while (index < bitcount)
	{
		if (skip_index(&index, &tetriminoes[(uint64_t)depth], board_size))
			break ; // return (NULL); (?)
		if (bitarrset(bitarray(bitcount, FETCH), index, tetrilong) == 1)
		{
			answer = solve(tetriminoes, board_size, depth + 1);
			if (answer)
			{
				place_alphabet(answer, tetrilong, index, depth + 'A');
				bitcount = 0;
				return (answer);
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
