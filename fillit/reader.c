/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:13:48 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/01/20 20:37:04 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
# define TETRIMINO_WIDTH 4 //move to .h file

/*
	Reads and validates the tetriminos.
*/

static int	validater(char str, char tetriminoes, int *count)


/*still needed to check the teriminoe's width*/
static unsigned short	get_next_tetrimino(int fd, unsigned char ***tetriminoes, int *count)
{
	int				line_count;

	line_count = count * 5;
	while (line_count <= count * 5 + 4)
	{
		status = get_next_line(fd, tetriminoes);
		line_count++;
	}
	return ();
}

# define TETRIMINO_WIDTH 4 //move to .h file



static unsigned char	get_index(line_idx, character_idx)
{
	return ();
}

/*
	Assumes valid length of lines.
	# (hashtag) for tetrimino
*/


static short	*get_tetriminoes(int fd, unsigned char *tetrimino_count)
{
	char			**tetriminoes[26];
	unsigned char	count;
	int				status;

	count = 0;
	status = 1;
	while (status == 1)
	{
		status = get_next_tetrimino(fd, &tetriminoes[count], &count);
		count++;
	}
	if (status == -1 || count < 1 || count > 26)
		return (NULL); // should be "error"
	*tetrimino_count = count;
	while (count--)
		convert_to_short(tetriminoes[count]);

}




unsigned short	convert_to_short(const char **tetrimino_string)
{
	unsigned short	tetrimino;
	unsigned char	line_idx;
	unsigned char	character_idx;
	char			character;

	tetrimino = 0;
	line_idx = 0;
	while (line_idx < TETRIMINO_WIDTH)
	{
		//if (ft_strlen(tetrimino_string[line_idx]) != 4)
		character_idx = TETRIMINO_WIDTH;
		while (0 <= character_idx + 1)
		{
			if (tetrimino_string[line_idx][character_idx] == '#')
			{
				tetrimino = tetrimino | (0x1 << get_index(line_idx, character_idx));
			}
			else if ()
			{
				tetrimino = 0b0110110000000000;
			}
			else
			{

			}
			character_idx--;
		}
		line_idx--;;
	}
}

#include <fcntl.h>

static int	open_input(const char *filename)
{
	return (open(filename, O_RDONLY));
}