/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/01/19 06:38:18 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

static int	open_input(const char *filename)
{
	return (open(filename, O_RDONLY));
}

static short	*get_tetriminoes(int fd, unsigned char *tetrimino_count)
{
	char			**tetriminoes[26];
	unsigned char	count;
	int				status;

	count = 0;
	status = 1;
	while (status == 1)
	{
		tetriminoes[count] = get_next_tetrimino(fd, &status, &tetriminoes[count]);
		count++;
	}
	if (status == -1 || count < 1 || count > 26)
		return (error());
	*tetrimino_count = count;
	while (count--)
		convert_to_short(tetriminoes[count]);
}

static int	fillit(int fd)
{
	short			*tetriminoes;
	size_t			tetrimino_count;
	unsigned char	board_size;
	char			*solution;

	tetriminoes = get_tetriminoes(fd, &tetrimino_count);
	board_size = min_board(tetrimino_count);
	solution = NULL;
	while (!solution)
	{
		bitarray(board_size, UPDATE);
		solution = solve(tetriminoes, board_size++, 0);
	}
	display_solution_board(solution);
	return (0);
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
