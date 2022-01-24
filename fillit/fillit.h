/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:32 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 16:53:06 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "./libft_mrozhnov/libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>

//# define BUFF_SIZE 21

typedef struct s_tetriminoes
{
	int				width;
	int				height;
	//char			letters;
	//			index;
}				t_tetriminoes;

long			errors(char *message, long output);
unsigned short	convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_string);

#endif
