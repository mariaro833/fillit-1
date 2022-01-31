/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:55:47 by thakala           #+#    #+#             */
/*   Updated: 2022/01/31 14:01:55 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	bitarrset(t_bitarr *bitarr, uint64_t index, uint64_t bitstring)
{
	uint64_t	left;
	uint64_t	right;
	uint64_t	index_division;

	split_long(bitstring, index, &left, &right);
	index_division = index / ULONG_BITCOUNT;
	if (!(bitarr->arr[index_division] & left) && \
		!(bitarr->arr[index_division + 1] & right))
	{
		bitarr->arr[index_division] |= left;
		bitarr->arr[index_division + 1] |= right;
		return (1);
	}
	return (0);
}
