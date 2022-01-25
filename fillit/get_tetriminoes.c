/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminoes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:52:45 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/25 12:23:06 by thakala          ###   ########.fr       */
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
	if (ret == -1 || ret == 0 || fd == -1)
		return (0);
	while (ret)
	{
		if ((ret == 21 && buffer[20] != '\n') || !(validation(tetriminoes, buffer, count)))
			return (errors ("error\n", -1));
		if (ret == -1)
			return (errors ("reader_error\n", 2));
		buffer[ret] = '\0';
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
	count = 0;
	get_tetriminoes(fd, tetriminoes, &count);
	close (fd);
	function_loader_for_debugging();
//	system("leaks a.out");
	return (0);
}
