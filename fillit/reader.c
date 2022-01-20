/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:13:48 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/20 12:14:24 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
# define TETRIMINO_WIDTH 4 //move to .h file

/*
	Reads and validates the tetriminos.
*/

ssize_t	get_next_tetrimino(int fd, int *status, char ***tetrimino)
{
	char			buf[TETRIMINO_WIDTH + 2];
	ssize_t			read_bytes;
	unsigned char	line;

	line = 0;
	while (line < 4)
	{
		read_bytes = read(fd, buf, TETRIMINO_WIDTH + 1);
		if (read_bytes <= -1)
			return (-1);
		if (fd == -1 || read_bytes == 0)
			return (0);
		else if (read_bytes == TETRIMINO_WIDTH + 1)
		{
			if (buf[read_bytes] != '\n')
			{
				return (-1);
			}
			while ()
			{

			}
		}
		else if (read_bytes == 0)
		{

		}
		line++;
	}
	return ();
}

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
}
