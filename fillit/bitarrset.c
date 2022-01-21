/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:55:47 by thakala           #+#    #+#             */
/*   Updated: 2022/01/21 17:43:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	bitarrset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring)
{
	unsigned long	left;
	unsigned long	right;
	unsigned short	index_division;

	split_long(bitstring, index, &left, &right);
	index_division = index / ULONG_BITCOUNT;
	if (!(bitarr->arr[index_division] & left) \
		&& !(bitarr->arr[index_division + 1] & right))
	{
		bitarr->arr[index_division] |= left;
		bitarr->arr[index_division + 1] |= right;
		return (1);
	}
	return (0);
}

/*
split_long returns the value which split of the long has bits to set.
set only the side which is not 0. Faster or not? Test.

unsigned char	bitarrset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring)
{
	unsigned long	left;
	unsigned long	right;
	unsigned int	status;
	unsigned short	index_modulus;

	status = split_long(bitstring, &left, &right);
	index_modulus = index % ULONG_BITCOUNT;
	if (status == SPLIT_MIDDLE && !(bitarr->arr[index_modulus] & left) \
		&& !(bitarr->arr[index_modulus + 1] & right))
	{
		bitarr->arr[index_modulus] |= left;
		bitarr->arr[index_modulus + 1] |= right;
	}
	else if (status == SPLIT_LEFT && !(bitarr->arr[index_modulus] & left))
		bitarr->arr[index_modulus] |= left;
	else if (status == SPLIT_RIGHT && !(bitarr->arr[index_modulus + 1] & right))
		bitarr->arr[index_modulus + 1] |= right;
}*/
