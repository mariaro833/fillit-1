/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_reference.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:46:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/24 15:33:23 by mrozhnova        ###   ########.fr       */
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
