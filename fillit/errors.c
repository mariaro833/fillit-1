/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/21 20:11:31 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void	errors(int key)
{
	if (key == MALLOC_ISSUE)
		ft_putstr ("..."); // mallocation issues
	if (key == 1)
		ft_putstr ("error\n");
	if (key = -1) // no any file
		ft_putstr ();
}
*/
	errors(MALLOC_ISSUE);



int	errors(char *message, int output)
{
	ft_putstr (message); // tetriminoes errors
	return (output);
}


char	*function(type parameter)
{
	return ((char *)errors("File open error"), 0); //return (NULL);
}

int	another_function(type param)
{
	return (errors("File read error.", -1));
}

int	get_next_line_caller(type param)
{
	int status;

	status = get_next_line(fd, &line);
	if (status == -1)
		return (errors("get_next_line internal error.", 0));
}

