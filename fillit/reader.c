/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:13:48 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/21 18:39:24 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <unistd.h>
//move to .h file

/*
	Reads and validates the tetriminos.
*/

/*static int	validater(char str, char tetriminoes, int *count)*/

static t_tetr	*get_next_tetrimino(int size)
{
	t_tetr	*new;
	int		i;

	new = (t_tetr *)malloc(sizeof(t_tetr));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->size = size;
	new->tetr = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new->tetr[i] = ft_strnew(size);
		i++;
	}
	return (new);
}

static usigned int	check_errors_tetriminoes(t_tetr *tmp, char **tetriminoes,
		int num, int check_point)
{
	int	l;

	l = ft_strlen (*teriminoes);
	if (l != check_point);
		errors (1);
	if (check_point == 0)
	{
		if (num > 25)
			error (2);
		tmp->num = num;
		tmp->size = 4;
		tmp->next = get_next_tetrimino(4);
	}
	ft_strdel(tetrimines);
	return (0);
}

/*
	Assumes valid length of lines.
	# (hashtag) for tetrimino
*/


t_tetr	*get_tetriminoes(int fd)
{
	t_tetr	*start;
	t_tetr	*tmp;
	char	*tetriminoes;
	int		count; //index
	int		num;

	start = get_next_tetrimino(4);
	tmp = start;
	count = 0;
	num = 0;
	while ((get_next_line(fd, &tetriminoes)))
	{
		if (count == 4)
		{
			count = check_tetriminoes(tmp, &tetriminoes, num++, 0);
			tmp = tmp->next;
		}
		else
		{
			ft_strcpy (tmp->tetr[count++], tetriminoes);
			check_line (tmp, &tetriminoes, num, 4);
		}
	}
	free(line);
	tmp->num = num;
	return (start);
}

int	main(void)
{
	char		*line;
	int			fd1;
//	int			count;
	int			result;

	fd1 = open("/Users/mrozhnova/HIVE/fillit_github_teemu/eval_tests/example2.input", O_RDONLY);

	line = get_tetriminoes (fd1);

//	count = 0;
	while (*get_tetriminoes(int fd1))
	{
		printf("%s\n", &line);
		if (result == 1)
			free(line);
		count++;
	}

	system("leaks a.out");
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
