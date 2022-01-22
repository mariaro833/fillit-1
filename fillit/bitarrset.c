/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:55:47 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 17:57:18 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*

bitarr:
0000 0000-0000 0000-0000 0000-0*00 0000, * ->len (still counted in in the board)
bitstring:
0000 0001
index:
20
bitarr->len:
26
0000 0000-0000 0000-0000 0000-0*00 0000
    _    -    _    -   0 0000-001
1234 5670 1234 5670 1234 5670 1234 5670 (modulo 8)
1234 5678 9012 3456 7890
 left: 0000
right: 0010

bitarr->len % CHAR_BITCOUNT == bitarr->len % 8 == 26 % 8 == 2
index % CHAR_BITCOUNT - 1 == index % 8 - 1 == 20 % 8 - 1 == 4 - 1 == 3


*/

/*static unsigned char	check_len_overrun(unsigned long len, \
	unsigned long right, unsigned long index)
{
	unsigned short	shift;

	shift = ULONG_BITCOUNT - len % ULONG_BITCOUNT + index % ULONG_BITCOUNT;
	return (((right >> shift) << shift) == right);
}*/

unsigned char	bitarrset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring)
{
	unsigned long	left;
	unsigned long	right;
	unsigned short	index_division;
	unsigned long	len_division;

	split_long(bitstring, index, &left, &right);
	index_division = index / ULONG_BITCOUNT;
	len_division = bitarr->len / ULONG_BITCOUNT;
	/*if ((index_division == len_division - 1 && \
		!check_len_overrun(bitarr->len, left, index)) || \
		(index_division == len_division && \
		!check_len_overrun(bitarr->len, left, index) && \
		!check_len_overrun(bitarr->len, right, index)))
		return (0);*/
	if (!(bitarr->arr[index_division] & left) \
		&& !(bitarr->arr[index_division + 1] & right))
	{
		bitarr->arr[index_division] |= left;
		bitarr->arr[index_division + 1] |= right; //segfault
		return (1);
	}
	return (0);
}

/*
split_long returns the value which split of the long has bits to set.
set only the side which is not 0. Faster or not? Test.

USE RATHER:
!left !right

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
