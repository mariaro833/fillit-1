/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:40:56 by thakala           #+#    #+#             */
/*   Updated: 2022/01/28 11:18:26 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint64_t	ceiling_division(uint64_t dividend, \
	uint64_t divisor)
{
	uint64_t	division;
	uint64_t	remnant_truth;

	division = dividend / divisor;
	remnant_truth = !!(dividend % divisor);
	return (division + remnant_truth);
}

// bitarrfree

t_bitarr	*bitarray(uint64_t len, uint8_t flags)
{
	static t_bitarr	*bitarr;

	if (!bitarr)
		bitarr = (t_bitarr *)ft_memalloc(sizeof(t_bitarr));
	if (bitarr && ((flags & UPDATE && bitarr->size < len) || !bitarr->arr))
	{
		bitarr->len = len;
		free(bitarr->arr);
		bitarr->size = sizeof(uint64_t) * \
			ceiling_division(len, ULONG_BITCOUNT);
		bitarr->arr = (uint64_t *)malloc(bitarr->size);
		bitarr->size *= BYTE_BITCOUNT;
		if (!bitarr->arr)
		{
			free(bitarr); //optional bitarrdel here
			bitarr = NULL;
			return (NULL);
		}
		bitarrzero(bitarr);
	}
	else if (flags & UPDATE && bitarr->len < len)
		bitarr->len = len;
	return (bitarr);
}
