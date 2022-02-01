/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/01 14:52:45 by thakala          ###   ########.fr       */
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

/*uint16_t	set_index(t_bitarr *bitarr)
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
}*/

/*
	save division by using a height variable row
	use local copy to safe dereferenciation time?
	t_tetri local;

	local = *tetrimino;
*/

uint8_t	skip_index(uint16_t *index, t_tetri *tetrimino, uint16_t board_size)
{
	if (tetrimino->col > board_size - tetrimino->width)
	{
		tetrimino->col = 0;
		tetrimino->row++;
		*index += tetrimino->width - 1;
		return (tetrimino->row <= board_size - tetrimino->height);
	}
	return (1);
}

/* list of tetriminoes ends with 0UL */

char	*solve(t_tetri *tetriminoes, uint16_t board_size, t_bitarr *bitarr)
{
	uint16_t		index;
	uint64_t		tetrilong;
	char			*answer;

	if (!tetriminoes->shape)
		return (ft_strnewset('.', board_size * board_size));
	index = 0;
	tetrilong = pad_short(tetriminoes->shape, (uint8_t)board_size);
	while (skip_index(&index, tetriminoes, board_size))
	{
		if (bitarrset(bitarr, index, tetrilong))
		{
			answer = solve(tetriminoes + 1, board_size, bitarr);
			if (answer)
			{
				place_alphabet(answer, tetrilong, index, tetriminoes);
				return (answer);
			}
			bitarrunset(bitarr, index, tetrilong);
		}
		tetriminoes->col++;
		index++;
	}
	tetriminoes->col = 0;
	tetriminoes->row = 0;
	return (NULL);
}
