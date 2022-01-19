/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:40:56 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 15:46:37 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned long	ceiling_division(unsigned long dividend, \
	unsigned long divisor)
{
	unsigned long	division;
	unsigned long	remnant_truth;

	division = dividend / sizeof(unsigned long);
	remnant_truth = !!(dividend % sizeof(unsigned long));
	return (division + remnant_truth);
}

t_bitarr	*bitarray(unsigned long len, unsigned char flags)
{
	static t_bitarr	*bitarr;

	if (!bitarr)
		bitarr = (t_bitarr *)ft_memalloc(sizeof(t_bitarr));
	if (!bitarr)
		return (NULL);
	if (flags & UPDATE || !bitarr->arr)
	{
		bitarr->len = len;
		bitarr->arr = (unsigned long *)malloc(sizeof(unsigned long) * \
			ceiling_division(len, ULONG_BITCOUNT));
		if (!bitarr->arr)
		{
			free(bitarr);
			return (NULL);
		}
		bitarrzero(bitarr);
	}
	return (bitarr);
}
