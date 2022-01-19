/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:14:20 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 16:18:17 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	split_long(unsigned long input, unsigned long index, \
	unsigned long *left, unsigned long *right)
{
	index %= ULONG_BITCOUNT;
	*left = input >> ULONG_BITCOUNT - index;
	*right = input << index;
}
