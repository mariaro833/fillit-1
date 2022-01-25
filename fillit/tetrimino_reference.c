/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/25 20:37:30 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void	free_tetrimino_reference(t_tetri *tetris, uint8_t len)
{
	uint8_t	i;

	i = 0;
	while (i++ < len)
		free(tetris++);
}*/

/*
	Sort the tetrimino_reference list and use binary search on it.
*/

t_tetri	*tetrimino_reference(t_tetri *tetriminoes, \
	uint8_t flag)
{
	static t_tetri	*tetris;
	uint8_t			i;

	if (flag & SET && tetriminoes)
	{
		tetris = (t_tetri *)malloc(sizeof(t_tetri) * (TETRIMINO_TYPES + 1));
		if (tetris)
		{
			i = 0;
			while (tetriminoes[i].shape)
			{
				tetris[i].shape = tetriminoes[i].shape;
				tetris[i].width = tetriminoes[i].width;
				tetris[i].height = tetriminoes[i].height;
				i++;
			}
		}
	}
	else if ((flag & FREE) && tetris)
	{
		free(tetris);
		tetris = NULL;
	}
	return (tetris);
}
