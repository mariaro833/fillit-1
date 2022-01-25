/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/25 19:44:16 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	return (tetris);
}
