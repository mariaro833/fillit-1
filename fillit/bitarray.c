/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:40:56 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 13:33:06 by thakala          ###   ########.fr       */
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
	unsigned long	size;

	if (!bitarr)
		bitarr = (t_bitarr *)malloc(sizeof(t_bitarr));
	if (!bitarr)
		return (NULL);
	if (flags & UPDATE)
	{
		bitarr->len = len;
		//bitarr->size = sizeof(unsigned long) * \
		//	ceiling_division(len, sizeof(unsigned long) * 8);
		size = 
		bitarr->arr = (unsigned long *)malloc(size);
	}
	return (bitarr);
}
