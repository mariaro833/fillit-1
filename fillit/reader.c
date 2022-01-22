/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:13:48 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/22 19:42:24 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
//move to .h file

/*
	Reads and validates the tetriminos.
*/

/*static int	validater(char str, char tetriminoes, int *count)*/

static char	**get_tetrimino(int size)
{
	char	**new_tetrimino;
	int		i;

	new_tetrimino = (char **)malloc(size*sizeof(char *));
	if (!new_tetrimino)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_tetrimino[i] = ft_strnew(size);
		i++;
	}
	return (new_tetrimino);
}

static unsigned int	check_tetriminoes(char *temp, char **tetriminoes,
		int tetr_num, int check_point)
{
	int	l;

	l = ft_strlen (*tetriminoes);
	if (l != check_point)
		errors ("error", -1);
	if (check_point == 0)
	{
		if (tetr_num > 25)
			errors ("error", -1);
		temp = get_tetrimino(4);
	}
	ft_strdel(tetriminoes);
	return (0);
}

/*
	Assumes valid length of lines.
	# (hashtag) for tetrimino
*/


char	*get_next_tetriminoes(int fd)
{
	char			**start;
	char			**temp;
	char			*tetriminoes;
	int				count;
	int				tetr_num;

	start = get_tetrimino(4);
	if (!start)
		return ((char *)errors("mallocation_issues", 0));
	temp = start;
	count = 0;
	tetr_num = 0;
	while ((get_next_line(fd, &tetriminoes)))
	{
		if (count == 4)
		{
			count = check_tetriminoes(temp, &tetriminoes, tetr_num++, 0);
		}
		else
		{
			ft_strcpy (&temp[count++], tetriminoes);
			check_tetriminoes (temp, &tetriminoes, tetr_num, 4);
		}
	}
	start = temp;
	return (start);
}

int		main(int argc, char **argv)
{
	char		*line;
	int			fd;

	if (argc != 2)
	{
		errors ("tetriminoes_file_missed\n", -1);
		return (-1);
	}
	fd = open("test0.txt", O_RDONLY);
	if (fd == -1)
	{
		errors ("open_file_error\n", -1);
		return (-1);
	}
	line = get_next_tetriminoes(fd);
	close (fd);
	while (get_next_tetriminoes(fd))
		printf ("%s\n", line);
//	system("leaks a.out");
	return (0);
}
/*
		status = get_next_tetrimino(fd, &tetriminoes[count], &count);
		count++;
	}
	if (status == -1 || count < 1 || count > 26)
		return (NULL); // should be "error"
	*tetrimino_count = count;
	while (count--)
		convert_to_short(tetriminoes[count]);
}*/

/*still needed to check the teriminoe's width*/
/*
static unsigned short	get_next_tetrimino(int fd, unsigned char ***tetriminoes, int *count)
{
	int				line_count;

	line_count = 0;
	while (line_count <= 4)
	{
		status = get_next_line(fd, tetriminoes);
		line_count++;
	}
	return ();
}

# define TETRIMINO_WIDTH 4 //move to .h file



static unsigned char	get_index(line_idx, character_idx)
{
	return ();
}

unsigned short	convert_to_short(const char **tetrimino_string)
{
	unsigned short	tetrimino;
	unsigned char	line_idx;
	unsigned char	character_idx;
	char			character;

	tetrimino = 0;
	line_idx = 0;
	while (line_idx < 4)
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

#include <fcntl.h>

static int	open_input(const char *filename)
{
	return (open(filename, O_RDONLY));
}
*/
