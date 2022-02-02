/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:17:01 by thakala           #+#    #+#             */
/*   Updated: 2022/02/02 21:11:32 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_TESTS_H
# define EVAL_TESTS_H

# include "helpers/includes/helpers.h"

void	display_current_board(t_bitarr *bitarr, t_tetri *tetriminoes, \
	uint8_t board_size);
void	display_current_board_depth(t_bitarr *bitarr, t_tetri *tetriminoes, \
	uint8_t board_size, uint8_t recursion_depth);

#endif
