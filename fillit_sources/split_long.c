/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:14:20 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 15:59:35 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	split_long(uint64_t input, uint64_t index, \
	uint64_t *left, uint64_t *right)
{
	index %= ULONG_BITCOUNT;
	*left = input >> index;
	*right = 0;
	if (index)
		*right = input << (ULONG_BITCOUNT - index);
}
