/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitarrzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:48:20 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 15:52:32 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bitarrzero(t_bitarr *bitarr)
{
	unsigned long	count;

	count = 0;
	while (count * ULONG_BITCOUNT < bitarr->len)
		bitarr->arr[count++] = 0UL;
}
