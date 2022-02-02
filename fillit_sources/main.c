/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:48:17 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 03:58:09 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int				fd;
	uint8_t			count;
	static t_tetri	tetriminoes[27];

	if (argc != 2)
		return ((int)errors ("usage: Insert 1 argument after ./fillit\n", -1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ((int)errors ("open_error\n", 2));
	count = 0;
	if (get_tetriminoes(fd, tetriminoes, &count) <= 0)
		return ((int)errors ("error\n", -1));
	link_tetriminoes(tetriminoes);
	if (close (fd) == -1)
		return ((int)errors ("close_error\n", 2));
	return (fillit(tetriminoes, count));
}
