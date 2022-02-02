/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:32:55 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 03:36:53 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint8_t	bitarrcheck(t_bitarr *bitarr, uint16_t index)
{
	uint16_t	index_modulus;

	index_modulus = index % ULONG_BITCOUNT;
	return (bitarr->arr[index / ULONG_BITCOUNT] \
		& 1ULL << (ULONG_BITCOUNT - index_modulus));
}
