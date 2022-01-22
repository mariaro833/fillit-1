/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 15:28:50 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define FETCH (unsigned char)0b0
# define UPDATE (unsigned char)0b1

# define BYTE_BITCOUNT 8
# define ULONG_BITCOUNT 64

typedef struct s_bitarr
{
	unsigned long	*arr;
	unsigned long	len;
	unsigned long	size;
}	t_bitarr;

void			bitarrzero(t_bitarr *bitarr);
t_bitarr		*bitarray(unsigned long len, unsigned char flags);

/*# define SPLIT_LEFT 0
# define SPLIT_MIDDLE 1
# define SPLIT_RIGHT 2*/

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_width);
void			split_long(unsigned long input, unsigned long index, \
	unsigned long *left, unsigned long *right);
unsigned char	bitarrset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring);
void			bitarrunset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring);
#endif
