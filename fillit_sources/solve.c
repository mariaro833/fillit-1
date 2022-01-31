/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/31 21:05:01 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strnewset(char chr, uint16_t len)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string)
		((char *)ft_memset(string, chr, len + 1))[len] = '\0';
	return (string);
}

uint16_t	set_index(t_bitarr *bitarr)
{
	uint16_t	c;
	uint8_t		division;
	uint8_t		division_index;

	c = 0;
	division = 0;
	division_index = 0;
	while (c < bitarr->len)
	{
		division_index++;
		if (!(bitarr->arr[division] & (1 << (ULONG_BITCOUNT - division_index))))
			return (c);
		if (division_index == ULONG_BITCOUNT)
		{
			division_index = 0;
			division++;
		}
		c++;
	}
	return (c);
}

/*
	save division by using a height variable row
*/

uint8_t	skip_index(uint8_t *col, uint8_t *row, \
	uint16_t *index, t_tetri *tetrimino, uint16_t board_size)
{
	if (*col > board_size - tetrimino->width)
	{
		*col = 0;
		(*row)++;
		*index += tetrimino->width - 1;
		return (*row <= board_size - tetrimino->height);
	}
	return (1);
}

/* list of tetriminoes ends with 0UL */
/* tetriminoes[(uint64_t)depth] too big cast? */

char	*solve(t_tetri *tetriminoes, uint16_t board_size, char depth,
	t_bitarr *bitarr)
{
	uint8_t			col;
	uint8_t			row;
	uint16_t		index;
	uint64_t		tetrilong;
	char			*answer;

	if (!tetriminoes[(uint64_t)depth].shape)
		return (ft_strnewset('.', board_size * board_size));
	col = 0;
	row = 0;
	index = set_index(bitarr);//, tetriminoes[(uint64_t)depth].voids);
	tetrilong = pad_short(tetriminoes[(uint64_t)depth].shape, (uint8_t)board_size);
	while (skip_index(&col, &row, &index, &tetriminoes[(uint64_t)depth], board_size))
	{
		if (bitarrset(bitarr, index, tetrilong))
		{
			answer = solve(tetriminoes, board_size, depth + 1, bitarr);
			if (answer)
			{
				place_alphabet(answer, tetrilong, index, depth + 'A');
				return (answer);
			}
			bitarrunset(bitarr, index, tetrilong);
		}
		col++;
		index++;
	}
	return (NULL);
}
