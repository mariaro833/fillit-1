/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 17:50:48 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define FETCH (unsigned char)0b0
# define UPDATE (unsigned char)0b1

# define SET (unsigned char)0b10

# define I_0 0b1111000000000000UL
# define I_1 0b1000100010001000UL
# define J_0 0b1110001000000000UL
# define J_1 0b0100010011000000UL
# define J_2 0b1000111000000000UL
# define J_3 0b1100100010000000UL
# define L_0 0b1110100000000000UL
# define L_1 0b1100010001000000UL
# define L_2 0b0010111000000000UL
# define L_3 0b1000100011000000UL
# define O_0 0b1100110000000000UL
# define S_0 0b0110110000000000UL
# define S_1 0b1000110001000000UL
# define T_0 0b1110010000000000UL
# define T_1 0b0100110001000000UL
# define T_2 0b0100111000000000UL
# define T_3 0b1000110010000000UL
# define Z_0 0b1100011000000000UL
# define Z_1 0b0100110010000000UL

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

unsigned long	pad_short(unsigned short tetrimino, unsigned long index, \
	unsigned char board_width);
void			split_long(unsigned long input, unsigned long index, \
	unsigned long *left, unsigned long *right);
unsigned char	bitarrset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring);
void			bitarrunset(t_bitarr *bitarr, unsigned long index, \
	unsigned long bitstring);
void			place_alphabet(char **string, unsigned long tetrilong, \
	unsigned long index, char alphabet);
char			*solve(unsigned short *tetriminoes, unsigned char board_size, \
	char depth);
void			display_solution_board(char *solution, \
	unsigned long board_size);
#endif
