/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminoes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:52:45 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/25 17:34:03 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# include "helpers.h"
# include <stdlib.h>

static int	validation(t_tetriminoes *tetriminoes, char *line, int *count)
{
	int		i;
	int		hashs;
	int		total_connections;

	hashs = 0;
	total_connections = 0;
	i = 0;
	while (i < 20)
	{
		if (line[i] != '\n' && i % 5 == 4)
			return (0);
		else if ((line[i] != '#' && line[i] != '.') && i % 5 != 4)
			return (0);
		if (line[i] == '#')
			++hashs;
		i++;
	}
	if (hashs != 4 || *count > 26)
		return (0);
	else
	{
		convert_to_short(tetriminoes + *count, line);
		(*count)++;
	}
	return (1);
}

int	get_tetriminoes(int fd, t_tetriminoes *tetriminoes, int *count)
{
	char		buffer[BUFF_SIZE + 1];
	size_t		ret;
	size_t		ret_copy;

	ret = read(fd, &buffer, BUFF_SIZE);
	if (ret <= 19)
		return (0);
	while (ret)
	{
		buffer[ret] = '\0';
		if ((ret == 21 && buffer[20] != '\n') || !(validation(tetriminoes, buffer, count)))
			return (errors ("error\n", -1));
		if (ret == -1)
			return (errors ("reader_error\n", 2));
		(*count)++;
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return (1);
}

static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;

	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
}

void	tetrimino_reference_init(void)
{
	tetrimino_reference((t_tetri []) \
		{(struct s_tetri){I_0, 4U, 1U},
		(struct s_tetri){I_1, 1U, 4U},
		(struct s_tetri){J_0, 3U, 2U},
		(struct s_tetri){J_1, 2U, 3U},
		(struct s_tetri){J_2, 3U, 2U},
		(struct s_tetri){J_3, 2U, 3U},
		(struct s_tetri){L_0, 3U, 2U},
		(struct s_tetri){L_1, 2U, 3U},
		(struct s_tetri){L_2, 3U, 2U},
		(struct s_tetri){L_3, 2U, 3U},
		(struct s_tetri){O_0, 2U, 2U},
		(struct s_tetri){S_0, 3U, 2U},
		(struct s_tetri){S_1, 2U, 3U},
		(struct s_tetri){T_0, 3U, 2U},
		(struct s_tetri){T_1, 2U, 3U},
		(struct s_tetri){T_2, 3U, 2U},
		(struct s_tetri){T_3, 2U, 3U},
		(struct s_tetri){Z_0, 3U, 2U},
		(struct s_tetri){Z_1, 2U, 3U},
		(struct s_tetri){0U, 0U, 0U}}, SET);
}

int		main(int argc, char **argv)
{
	char				*line;
	int					fd;
	int					count;
	t_tetriminoes		tetriminoes[27];

	if (argc != 2)
		return (errors ("usage: Insert one argument after ./fillit\n", -1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (errors ("open_error\n", -1));
	tetrimino_reference_init();
	count = 0;
	get_tetriminoes(fd, tetriminoes, &count);
	if (close (fd) == -1)
		return (errors ("close_error\n", -1));
	function_loader_for_debugging();
//	system("leaks a.out");
	return (0);
}
