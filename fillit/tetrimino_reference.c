/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/25 16:34:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetrimino_reference(t_tetri *tetriminoes, \
	uint8_t flag)
{
	static const t_tetri	*tetrimino_list;

	if (flag & SET && tetriminoes)
		tetrimino_list = tetriminoes;
	return (tetrimino_list);
}
