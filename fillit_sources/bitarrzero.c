/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:48:20 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 04:30:21 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bitarrzero(t_bitarr *bitarr)
{
	uint64_t	count;

	count = 0;
	while (count * ULONG_BITCOUNT < bitarr->size)
		bitarr->arr[count++] = 0UL;
}
