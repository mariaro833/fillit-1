/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:31:19 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/23 13:13:07 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 	message				output			comments
**	error					-1		tetriminoes error;
** 	mallocation issues 		0
**	file reader error		2
**	file open error			2
*/

long	errors(char *message, long output)
{
	ft_putstr (message);
	return (output);
}
