/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrunset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:08:36 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 15:28:40 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bitarrunset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring)
{
	unsigned long	left;
	unsigned long	right;
	unsigned short	index_division;

	split_long(bitstring, index, &left, &right);
	index_division = index / ULONG_BITCOUNT;
	bitarr->arr[index_division] ^= left;
	bitarr->arr[index_division + 1] ^= right;
}
