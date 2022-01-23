/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:40:56 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 12:53:32 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

static unsigned long	ceiling_division(unsigned long dividend, \
	unsigned long divisor)
{
	unsigned long	division;
	unsigned long	remnant_truth;

	division = dividend / divisor;
	remnant_truth = !!(dividend % divisor);
	return (division + remnant_truth);
}

t_bitarr	*bitarray(unsigned long len, unsigned char flags)
{
	static t_bitarr	*bitarr;

	if (!bitarr)
		bitarr = (t_bitarr *)ft_memalloc(sizeof(t_bitarr));
	if (bitarr && ((flags & UPDATE && bitarr->size < len) || !bitarr->arr))
	{
		bitarr->len = len;
		free(bitarr->arr);
		bitarr->size = sizeof(unsigned long) * \
			ceiling_division(len, ULONG_BITCOUNT);
		bitarr->arr = (unsigned long *)malloc(bitarr->size);
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
