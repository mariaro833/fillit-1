/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:14:20 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 16:11:16 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	split_long(unsigned long input, unsigned long index, \
	unsigned long *left, unsigned long *right)
{
	index %= ULONG_BITCOUNT;
	*left = input >> index;
	*right = 0;
	if (index)
		*right = input << (ULONG_BITCOUNT - index);
}
