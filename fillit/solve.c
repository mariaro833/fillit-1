/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:49:21 by thakala           #+#    #+#             */
/*   Updated: 2022/01/14 16:51:27 by mrozhnova        ###   ########.fr       */
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

    size_t  board_size;

    board_size = 0;
    while (board_size * board_size < 4 * tetrimino_count)
        board_size++;
    return (board_size * board_size);
}


char	*display_solution_board(long **bitarray, short *tetriminos)
{


}

#define FETCH 0b01
#define CLEAR 0b10

typedef struct  s_bitarray
{
    unsigned long  *arr;
    size_t          len;
}   t_bitarray;

t_bitarray  *bitarray(size_t size, unsigned char flag)
{
    static t_bitarray   *bitarr;

    if (flag & FETCH)
    {
        if (!bitarr)
            bitarr = bitarrnew(size);
    }
    else if (flag & CLEAR)
    {
        bitarrdel(&bitarr);
    }
    return (bitarr);
}

void    bitarrzero(t_bitarray *bitarr)
{
    size_t  idx;

    idx = 0;
    while (idx < bitarr->len)
        bitarr->arr[idx++] = 0UL;
}

/*
bitcount = size
ul_size = sizeof(unsigned long) == 8UL
bitcount == 64
    bitcount / ul_size
    !!(bitcount % ul_size)

    64 / 8UL == 8
    !!(64 % 8UL) == !!(0) == !1 == 0

bitcount == 65
    66 / 8UL == 8
    !!(66 % 8UL) == !!(2) == !0 == 1
*/

size_t  ceiling_division(size_t dividend, size_t divisor)
{
    size_t  division;
    size_t  remanant_truth;

    division = size / sizeof(unsigned long);
    remanant_truth = !!(size % sizeof(unsigned long));
    return (division + remnant_truth);
}

t_bitarray  *bitarrnew(size_t size)
{
    t_bitarray  *bitarr;

    bitarr = (t_bitarray *)ft_memalloc(sizeof(t_bitarray));
    if (!bitarr)
        return (NULL);
    bitarr->len = ceiling_division(size, sizeof(unsigned long));
    bitarr->arr = (unsigned long *)malloc(sizeof(unsigned long) * bitarr->len);
    if (!bitarr->arr)
        return (NULL);
    bitarrzero(bitarr);
    return (bitarr);
}

static char  depth(char direction)
{
    static char depth;

    depth += direction;
    return (depth);
}

/*
THE MAIN ISSUE HERE:
Can we translate the bit array into our textual solution?
We need to generate (after the solution has been found)
 the string of the solution with the correct alphabets.
We know:
-the size of the malloc we need to make by the board_size.
-the index for each tetrimino
We could know:
-the depth of the recursion (which gives us the alphabet in question)



solve(size_t depth)
solve(0)    alphabet[depth] == 'A'
 solve(1)    alphabet[depth] == 'B'
  solve(2)    alphabet[depth] == 'C'
   solve(3)    alphabet[depth] == 'D'
   */

char	*solve(short *tetriminos, size_t board_size, char depth)
{
	int	tetr_pos;

	tetr_pos = tetriminos / bord_size;

	while(tetriminos)
//		if(ceiling_division((board_size)))
			if (solve(tetriminos, board_size, depth + 1))
				return (1);
			next_tetrimino(tetriminos, board_size);
	

}

