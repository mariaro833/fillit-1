/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:42:42 by thakala           #+#    #+#             */
/*   Updated: 2022/01/24 15:21:26 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
	Assumes valid length of lines.
	# (hashtag) for tetrimino
*/

unsigned short	convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_string)
{
	int		i;
	char	*binary_tetr;
	char	*temp;

	if (!tetrimino_string)
		return (errors ("error", -1));

	binary_tetr = (char *)malloc(24 + 1);
	ft_strcpy (binary_tetr, "");
	temp = tetrimino_string;
	i = 0;
	while (temp[i] != '#')
		i++;
	while (temp)
	{
		while (i <= 24)
		{
			if (temp[i] == '#')
				ft_strcat (binary_tetr, "1");
			else if (temp[i] == '.')
				ft_strcat (binary_tetr, "0");
			++i;
		}
		temp++;
//		return (binary_tetr);
		return (0);
	}
	return (0);
}


/*
unsigned short	convert_to_short(const char **tetrimino_string)


{
	unsigned short	tetrimino;
	unsigned char	line_idx;
	unsigned char	character_idx;
	char			character;

	tetrimino = 0;
	line_idx = 0;
	while (line_idx < TETRIMINO_WIDTH)
	{
		//if (ft_strlen(tetrimino_string[line_idx]) != 4)
		character_idx = TETRIMINO_WIDTH;
		while (0 <= character_idx + 1)
		{
			if (tetrimino_string[line_idx][character_idx] == '#')
			{
				tetrimino = tetrimino | (0x1 << get_index(line_idx, character_idx));
			}
			else if ()
			{
				tetrimino = 0b0110110000000000;
			}
			else
			{

			}
			character_idx--;
		}
		line_idx--;;
	}
}*/
