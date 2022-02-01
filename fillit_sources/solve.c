/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/01 23:01:10 by thakala          ###   ########.fr       */
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

char	*solve(t_tetri *tetriminoes, uint16_t board_size, t_bitarr *bitarr, \
	uint64_t pad_short(uint16_t tetrimino, uint8_t board_size))
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
			answer = solve(tetriminoes + 1, board_size, bitarr, pad_short);
			if (answer)
				return (place_alphabet(answer, tetrilong, index, tetriminoes));
			bitarrunset(bitarr, index, tetrilong);
		}
		tetriminoes->col++;
		index++;
	}
	tetriminoes->col = 0;
	tetriminoes->row = 0;
	return (NULL);
}
