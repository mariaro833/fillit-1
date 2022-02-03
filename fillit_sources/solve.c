/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/03 19:36:22 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

	void display_current_board_depth(t_bitarr *bitarr, t_tetri *tetriminoes, \
	uint8_t board_size, uint8_t recursion_depth);
	void display_current_board_depth_cursor(t_bitarr *bitarr, \
	t_tetri *tetriminoes, uint8_t board_size, uint8_t recursion_depth, \
	uint16_t index);


char	*ft_strnewset(char chr, uint16_t len)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string)
		((char *)ft_memset(string, chr, len + 1))[len] = '\0';
	return (string);
}

/*
	please improve the search with binary search tree!
	linear search like this while loop could be way slower?
	Look into the algorithm to create such binary tree numerals.
	Only put into gear such optimisation for boards that it is necessary for.
*/

uint16_t	set_index(t_tetri *tetriminoes, uint8_t board_size, \
	t_bitarr *bitarr)
{
	t_tetri		previous;
	uint8_t		sum;
	uint16_t	index;

	previous = *(tetriminoes - tetriminoes->previous);
	index = board_size * previous.row + previous.col + \
		previous.packing_gap * (!!tetriminoes->previous) + tetriminoes->voids;
	tetriminoes->row = previous.row;
	sum = previous.col + previous.packing_gap * !!tetriminoes->previous;
	if (sum > board_size - tetriminoes->width) //width greater than board_size?
	{
		tetriminoes->row++;
		tetriminoes->col = sum % board_size;
	}
	else
		tetriminoes->col = sum;
	if (tetriminoes->row > board_size - tetriminoes->height)
		return ((uint16_t)(-1));
	while (bitarrcheck(bitarr, index))
	{
		if (tetriminoes->col > board_size - tetriminoes->width)
		{
			tetriminoes->col = 0;
			tetriminoes->row++;
			index += tetriminoes->width - 1;
		}
		else
		{
			index++;
			tetriminoes->col++;
		}
	}
	return (index - tetriminoes->voids);
}

uint8_t	skip_index(uint16_t *index, t_tetri *tetrimino, uint16_t board_size)
{
	if (tetrimino->col > board_size - tetrimino->width)
	{
		tetrimino->col = 0;
		tetrimino->row++;
		*index += tetrimino->width - 1;
	}
	return (tetrimino->row <= board_size - tetrimino->height);
}

char	*solve(t_tetri *tetriminoes, uint16_t board_size, t_bitarr *bitarr, \
	uint64_t pad_short(uint16_t tetrimino, uint8_t board_size))
{
	uint16_t		index;
	uint64_t		tetrilong;
	char			*answer;

	if (!tetriminoes->shape)
		return (ft_strnewset('.', board_size * board_size));
	index = set_index(tetriminoes, (uint8_t)board_size, bitarr);
	tetrilong = pad_short(tetriminoes->shape, (uint8_t)board_size);
	while (skip_index(&index, tetriminoes, board_size))
	{
		system("clear");
		display_current_board_depth_cursor(bitarr, tetriminoes, (uint8_t)board_size, tetriminoes->depth, index);
		if (bitarrset(bitarr, index, tetrilong))
		{
			//system("clear");
			//display_current_board_depth(bitarr, tetriminoes, (uint8_t)board_size, tetriminoes->depth);
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
