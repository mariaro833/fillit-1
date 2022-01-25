/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminoes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:52:45 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/25 20:36:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# include "helpers.h"
# include <stdlib.h>

static int	validation(t_tetri *tetrimino, char *line)
{
	uint8_t		i;
	uint8_t		hashs;

	hashs = 0;
	i = 0;
	while (i < BUFF_SIZE - 1)
	{
		if (line[i] != '\n' && i % 5 == 4)
			return (0);
		else if ((line[i] != '#' && line[i] != '.') && i % 5 != 4)
			return (0);
		if (line[i] == '#')
			++hashs;
		i++;
	}
	if (hashs != 4)
		return (0);
	*tetrimino = *convert_to_short(line);
	return (!!tetrimino);
}

int	get_tetriminoes(int fd, t_tetri *tetriminoes, int *count)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	while (1)
	{
		ret = read(fd, &buffer, BUFF_SIZE);
		if (!ret)
			break ;
		if (ret < BUFF_SIZE - 1)
			return (-1);
		buffer[ret] = '\0';
		if ((ret == BUFF_SIZE && buffer[BUFF_SIZE - 1] != '\n') || \
			(ret == BUFF_SIZE - 1 && buffer[BUFF_SIZE - 2] != '\n') || \
			!validation(&tetriminoes[*count], buffer) || ++(*count) > 26)
			return (-1);
	}
	return (!!*count);
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
