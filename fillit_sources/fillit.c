/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:55:48 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 13:43:08 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//# include "helpers.h"

static uint16_t	min_board(uint16_t square_count)
{
	uint16_t	result;

	result = 2;
	while (result * result < square_count)
		result++;
	return (result);
}

static int	fillit(t_tetri *tetriminoes, uint16_t tetrimino_count)
{
	uint16_t	board_size;
	char		*solution;

	board_size = min_board(tetrimino_count * 4);
	solution = (char *)0;
	while (1)
	{
		bitarray(board_size * board_size, UPDATE);
		solution = solve(tetriminoes, board_size, 0);
		if (solution)
			break ;
		board_size++;
	}
	display_solution_board(solution, board_size);
	free(solution);
	return (0);
}

/*static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;

	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
}*/

int	main(int argc, char **argv)
{
	int				fd;
	int				count;
	static t_tetri	tetriminoes[27];

	if (argc != 2)
		return (errors ("usage: Insert one argument after ./fillit\n", -1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (errors ("open_error\n", 2));
	tetrimino_reference_init();
	count = 0;
	if (get_tetriminoes(fd, tetriminoes, &count) <= 0)
		return (errors ("error\n", -1));
	if (close (fd) == -1)
		return (errors ("close_error\n", 2));
//function_loader_for_debugging();
//	system("leaks a.out");
	return (fillit(tetriminoes, count));
}
