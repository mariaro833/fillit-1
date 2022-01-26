/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 12:06:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	tetrimino_reference_init(void)
{
	tetrimino_reference((t_tetri []) \
		{(struct s_tetri){I_0, 4U, 1U},
		(struct s_tetri){I_1, 1U, 4U},
		(struct s_tetri){J_0, 3U, 2U},
		(struct s_tetri){J_1, 2U, 3U},
		(struct s_tetri){J_2, 3U, 2U},
		(struct s_tetri){J_3, 2U, 3U},
		(struct s_tetri){L_0, 3U, 2U},
		(struct s_tetri){L_1, 2U, 3U},
		(struct s_tetri){L_2, 3U, 2U},
		(struct s_tetri){L_3, 2U, 3U},
		(struct s_tetri){O_0, 2U, 2U},
		(struct s_tetri){S_0, 3U, 2U},
		(struct s_tetri){S_1, 2U, 3U},
		(struct s_tetri){T_0, 3U, 2U},
		(struct s_tetri){T_1, 2U, 3U},
		(struct s_tetri){T_2, 3U, 2U},
		(struct s_tetri){T_3, 2U, 3U},
		(struct s_tetri){Z_0, 3U, 2U},
		(struct s_tetri){Z_1, 2U, 3U},
		(struct s_tetri){0U, 0U, 0U}}, SET);
}
