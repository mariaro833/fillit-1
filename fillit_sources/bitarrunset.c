/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrunset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:08:36 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 15:48:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bitarrunset(t_bitarr *bitarr, uint64_t index, \
	uint64_t bitstring)
{
	uint64_t	left;
	uint64_t	right;
	uint64_t	index_division;
	uint64_t	len_division;

	split_long(bitstring, index, &left, &right);
	index_division = index / ULONG_BITCOUNT;
	len_division = bitarr->len / ULONG_BITCOUNT;
	if (index_division <= len_division)
		bitarr->arr[index_division] ^= left;
	if (index_division + 1 <= len_division)
		bitarr->arr[index_division + 1] ^= right;
}
