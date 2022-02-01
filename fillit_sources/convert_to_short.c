/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:33:50 by thakala           #+#    #+#             */
/*   Updated: 2022/02/01 20:22:07 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint16_t	shift_left(uint16_t bitstring)
{
	while (!(bitstring & (1 << 15)))
		bitstring <<= 1;
	return (bitstring);
}

static t_tetri	*match_binary_tetrimino(t_tetri *tetrimino)
{
	static uint8_t	count;
	t_tetri_		*tetri_ref;

	tetri_ref = tetrimino_reference(NULL, FETCH);
	if (tetri_ref)
	{
		while (tetri_ref->shape)
		{
			if (shift_left(tetri_ref->shape) == tetrimino->shape)
			{
				tetrimino->shape = tetri_ref->shape;
				tetrimino->width = tetri_ref->width;
				tetrimino->height = tetri_ref->height;
				tetrimino->col = 0U;
				tetrimino->row = 0U;
				tetrimino->depth = count++;
				return (tetrimino);
			}
			tetri_ref++;
		}
	}
	free(tetrimino);
	return (NULL);
}

t_tetri	*convert_to_short(char *tetrimino_str)
{
	t_tetri		*tetrimino;
	uint8_t		c;
	uint8_t		void_flag;

	tetrimino = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	if (!tetrimino)
		return ((t_tetri *)errors("mallocation issue", 0));
	c = 0;
	void_flag = (uint8_t)(-1);
	while (1)
	{
		tetrimino_str += tetrimino_str[c] == '\n';
		if (tetrimino_str[c] == '#')
		{
			if (void_flag == (uint8_t)(-1))
				void_flag = c;
			tetrimino->shape |= 1 << void_flag;
		}
		if (++c >= TETRIMINO_LEN)
			break ;
		tetrimino->shape <<= 1;
	}
	return (match_binary_tetrimino(tetrimino));
}
