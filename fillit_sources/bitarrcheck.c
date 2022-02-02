/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:32:55 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 04:35:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t	bitarrcheck(t_bitarr *bitarr, uint16_t index)
{
	uint16_t	index_modulus;

	index_modulus = index % ULONG_BITCOUNT;
	return ((bitarr->arr[index / ULONG_BITCOUNT] \
		& 1ULL << (ULONG_BITCOUNT - index_modulus - 1)));
}

/*uint8_t	bitarrcheck(t_bitarr *bitarr, uint16_t index)
{
	uint16_t	index_modulus;

	index_modulus = index % ULONG_BITCOUNT;
	return ((uint8_t)((bitarr->arr[index / ULONG_BITCOUNT] \
		& 1ULL << (ULONG_BITCOUNT - index_modulus)) \
		>> (ULONG_BITCOUNT - index_modulus)));
}*/
