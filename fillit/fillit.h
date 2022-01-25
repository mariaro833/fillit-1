/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/25 19:21:19 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//#include "./libft_mrozhnov/libft.h"
# include "libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 21
# define FETCH (unsigned char)0b0
# define UPDATE (unsigned char)0b1
# define SET (unsigned char)0b10
# define TETRIMINO_TYPES 19
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

typedef struct s_tetriminoes
{
	int				width;
	int				height;
	//char			letters;
	//			index;
}				t_tetriminoes;

typedef struct s_tetrimino
{
	uint16_t	binary_tetrimino;
	uint8_t		width;
	uint8_t		height;
	uint8_t		voids;
	char		debug_alphabet;
}		t_tetrimino;

typedef struct s_bitarr
{
	unsigned long	*arr;
	unsigned long	len;
	unsigned long	size;
}	t_bitarr;

typedef struct s_tetri
{
	uint16_t	shape;
	uint8_t		width;
	uint8_t		height;
	/*uint8_t	voids;*/
}	t_tetri;

long			errors(char *message, long output);
t_tetri			*convert_to_short(char *tetrimino_string);
//unsigned short		convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_string);

t_tetri			*tetrimino_reference(t_tetri *tetriminoes, uint8_t flag);

#endif
