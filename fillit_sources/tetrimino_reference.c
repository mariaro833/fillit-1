/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 04:10:16 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri_	*tetrimino_reference(t_tetri_ *tetriminoes, \
	uint8_t flag)
{
	static t_tetri_	*tetris;
	uint8_t			i;

	if (flag & SET && tetriminoes)
	{
		tetris = (t_tetri_ *)malloc(sizeof(t_tetri_) * (TETRIMINO_TYPES + 1));
		if (tetris)
		{
			i = 0;
			while (tetriminoes[i].shape)
			{
				tetris[i].shape = tetriminoes[i].shape;
				tetris[i].width = tetriminoes[i].width;
				tetris[i].height = tetriminoes[i].height;
				tetris[i].packing_gap = tetriminoes[i].packing_gap;
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

void	tetrimino_reference_init(void)
{
	tetrimino_reference((t_tetri_ []) \
		{(struct s_tetri_){I_0, 4U, 1U, 4U},
		(struct s_tetri_){I_1, 1U, 4U, 1U},
		(struct s_tetri_){J_0, 3U, 2U, 3U},
		(struct s_tetri_){J_1, 2U, 3U, 2U},
		(struct s_tetri_){J_2, 3U, 2U, 3U},
		(struct s_tetri_){J_3, 2U, 3U, 2U},
		(struct s_tetri_){L_0, 3U, 2U, 3U},
		(struct s_tetri_){L_1, 2U, 3U, 2U},
		(struct s_tetri_){L_2, 3U, 2U, 3U},
		(struct s_tetri_){L_3, 2U, 3U, 2U},
		(struct s_tetri_){O_0, 2U, 2U, 2U},
		(struct s_tetri_){S_0, 3U, 2U, 2U},
		(struct s_tetri_){S_1, 2U, 3U, 2U},
		(struct s_tetri_){T_0, 3U, 2U, 3U},
		(struct s_tetri_){T_1, 2U, 3U, 2U},
		(struct s_tetri_){T_2, 3U, 2U, 3U},
		(struct s_tetri_){T_3, 2U, 3U, 2U},
		(struct s_tetri_){Z_0, 3U, 2U, 2U},
		(struct s_tetri_){Z_1, 2U, 3U, 2U},
		(struct s_tetri_){0U, 0U, 0U, 0U}}, SET);
}
