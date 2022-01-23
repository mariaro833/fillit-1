/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_reference.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 17:48:30 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	*tetrimino_reference(unsigned short *tetriminoes, \
	unsigned char flag)
{
	static const unsigned short	*tetrimino_list;

	if (flag & SET && tetriminoes)
		tetrimino_list = tetriminoes;
	return (tetrimino_list);
}
