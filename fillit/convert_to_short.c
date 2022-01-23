/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:42:42 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 14:39:18 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define TETRIMINO_WIDTH 4 //move to .h file


static unsigned char	get_index(line_idx, character_idx)
{
	return ();
}

/*
	Assumes valid length of lines.
	# (hashtag) for tetrimino
*/

unsigned short	convert_to_short(const char **tetrimino_string)

/*
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
