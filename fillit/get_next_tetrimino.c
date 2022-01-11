/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:47:39 by thakala           #+#    #+#             */
/*   Updated: 2022/01/11 17:51:59 by thakala          ###   ########.fr       */
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
