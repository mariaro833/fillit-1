/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/22 14:14:37 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 	messge				output		comment
**	error				 - 1 	tetriminoes error;
** 	mallocation issues 	  0 	malloc issues
*/

long	errors(char *message, long output)
{
	ft_putstr (message); // tetriminoes errors
	return (output);
}

/*
void	check_tetriminoes_errors(char **tetriminoes)
{
	while ()

}*/

/*
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
*/
