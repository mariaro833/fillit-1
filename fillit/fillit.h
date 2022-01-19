/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 15:53:42 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define FETCH (unsigned char)0b0
# define UPDATE (unsigned char)0b1

# define ULONG_BITCOUNT 64

typedef struct s_bitarr
{
	unsigned long	*arr;
	unsigned long	len;
}	t_bitarr;

void			bitarrzero(t_bitarr *bitarr);
t_bitarr		*bitarray(unsigned long len, unsigned char flags);

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_width);

#endif
