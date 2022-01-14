/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/01/14 15:48:54 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

static int	open_input(const char *filename)
{
	return (open(filename, O_RDONLY));
}

static short	*get_tetriminos(int fd, unsigned char *tetrimino_count)
{
	char			**tetriminos[26];
	unsigned char	count;
	int				status;

	count = 0;
	status = 1;
	while (status == 1)
	{
		tetriminos[count] = get_next_tetrimino(fd, &status, &tetriminos[count]);
		count++;
	}
	if (status == -1 || count < 1 || count > 26)
		return (error());
	*tetrimino_count = count;
	while (count--)
		convert_to_short(tetriminos[count]);
}

static int	fillit(int fd)
{
	short	*tetriminos;
	size_t	tetrimino_count;

	tetriminos = get_tetriminos(fd, &tetrimino_count);
	bitarray(min_board(tetrimino_count), FETCH);
	solution = solve(tetriminos);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		// Handle the error.
		return (error());
	}
	fd = open_input(*(++argv));
	if (fd == -1)
		return (error());
	return (fillit(fd));
}
