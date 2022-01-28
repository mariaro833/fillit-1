/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminoes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:52:45 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/28 10:46:41 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int8_t	validation(t_tetri *tetrimino, char *line)
{
	uint8_t		i;
	uint8_t		hashs;
	t_tetri		*tmp;

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
	if (hashs != HASH_COUNT)
		return (0);
	tmp = convert_to_short(line);
	if (tmp)
		*tetrimino = *tmp;
	return (!!tetrimino);
}

int8_t	get_tetriminoes(int fd, t_tetri *tetriminoes, uint8_t *count)
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
