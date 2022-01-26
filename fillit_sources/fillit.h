/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 12:34:04 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 21
# define FETCH	0b0000U
# define UPDATE 0b0001U
# define SET	0b0010U
# define FREE	0b0100U
# define TETRIMINO_TYPES 19
# define TETRIMINO_LEN 16
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

typedef struct s_tetri
{
	uint16_t	shape;
	uint8_t		width;
	uint8_t		height;
	/*uint8_t	voids;*/
}	t_tetri;

void			bitarrzero(t_bitarr *bitarr);
t_bitarr		*bitarray(unsigned long len, unsigned char flags);
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
char			*solve(t_tetri *tetriminoes, uint8_t board_size, \
	char depth);
void			display_solution_board(char *solution, \
	unsigned long board_size);
long			errors(char *message, long output);
t_tetri			*convert_to_short(char *tetrimino_string);
t_tetri			*tetrimino_reference(t_tetri *tetriminoes, uint8_t flag);
void			tetrimino_reference_init(void);
int				get_tetriminoes(int fd, t_tetri *tetriminoes, int *count);

#endif
