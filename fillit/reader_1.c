/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:31:56 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/23 13:09:48 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validater(t_tetriminoes *tetriminoes, char *line, int *count)
{
	int		i;
	int		hashs;
	int		total_connections;

	hashs = 0;
	total_connections = 0;
	i = 0;
	while (i < 20)
	{
		if ((line[i] != '#' && line[i] != '.') && (i % 5 != 4 ))
			return (0);
		else if (line[i] != '\n' && i % 5 == 4)
			return (0);
		if (line[i] == '#')
			++hashs;
		i++;
	}
	if (hashs != 4 || *count > 26)
		return (0);
	else
	{
//		get_tetrimino(tetriminoes + *count, str, count);
		(*count)++;
	}
	return (1);
}

int	reader(int fd, t_tetriminoes *tetriminoes, int *count)
{
	char		buffer[BUFF_SIZE + 1];
	size_t		ret;
	size_t		ret_copy;

	ret = read(fd, &buffer, BUFF_SIZE);
	if (ret == -1 || ret == 0 || fd == -1)
		return (0);
	while (ret)
	{
		if ((ret == 21 && buffer[20] != '\n') || !(validater(tetriminoes, buffer, count)))
			errors ("error", -1);
		if (ret == -1)
			errors ("file_reader_error", 2);
		buffer[ret] = '\0';
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char				*line;
	int					fd;
	int					count;
	t_tetriminoes		tetriminoes[27];

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
	reader(fd, tetriminoes, &count);
	close (fd);
//	system("leaks a.out");
	return (0);
}