/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tetriminoes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:03:48 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 03:03:59 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	link_tetriminoes(t_tetri *tetriminoes)
{
	uint8_t	root;
	uint8_t	leaf;

	root = 0;
	while (tetriminoes[root].shape)
	{
		leaf = root + 1;
		while (tetriminoes[leaf].shape)
		{
			if (tetriminoes[leaf].shape == tetriminoes[root].shape)
			{
				(tetriminoes + leaf)->previous = leaf - root;
				break ;
			}
			leaf++;
		}
		root++;
	}
}
