/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 12:37:40 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define FETCH (unsigned char)0b0
# define UPDATE (unsigned char)0b1

typedef struct s_bitarr
{
	unsigned long	*arr;
	unsigned long	len;
	unsigned long	size;
}	t_bitarr;

unsigned long	pad_short(unsigned short tetrimino, unsigned short index, \
	unsigned char board_width);

#endif
