/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:49:21 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 12:39:30 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Receives as input the bitarray list of tetrimino shorts
		and smallest possible board_size calculated.
	Solves the smallest possible board.
	Returns the board for displaying in alphabets.
*/

/*
	The board state is stored in bits.
	Bits can only tell if there is a square of a piece in the position,
		and nothing else (no letter).
	Unless constructing the alphabetical board solution can be done,
		the solution is not a solution.
*/
/* Tetrimino has 4 squares -> calculate the least square that it can be.
	1:		4		4		2^2
	2:		8		9		3^2
	3:		12		16		4^2
	4:		16		16		4^2
	5:		20		25		5^2
	...
	26:		104		121		11^2 <-- might not be the largest solution*/

unsigned short	min_board(short *tetriminos)
{
	int	lines; // probably lines could come from get_next_tetrimino ?
	int	size;
/*
	while (*tetriminos)
	{
		if (ft_strchr == \n)
	}*/

	size = ((line / 4) * 6) << 2;
	

}


char	*display_solution_board(long **bitarray, short *tetriminos)
{


}


char	*solve(long **bitarray, short *tetriminos)
{
	int		result;
	int		board_size;
	long	bittarray;

	board_size = min_board(tetriminos);
	result = 0;
//	bitarray = ?
	while (!result)
	{
		if (bitarray)
			free (bitarray);
		bitarray = (char *)memalloc(sizeof(char)*(board_size + 1));
		result = get_next_tetrimino(bitarray, tetriminos); (?)
		board_size++;
	}
	return (display_solution_board(tetriminos, bitarray));
}
