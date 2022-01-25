
#include "fillit.h"

#define TETRIMINO_LEN 16


uint16_t	shift_left(uint16_t bitstring)
{
	while (!(bitstring & (1 << 15)))
		bitstring <<= 1;
	return (bitstring);
}

t_tetri	*match_binary_tetrimino(t_tetri *tetrimino)
{
	t_tetri	*tetri_ref;

	tetri_ref = tetrimino_reference(NULL, FETCH);
	while (tetri_ref->shape)
	{
		if (shift_left(tetri_ref->shape) == tetrimino->shape)
			return (tetri_ref->shape);
		tetri_ref++;
	}
	return ((t_tetri *)errors("error", 0));
}

t_tetri	*convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_str)
{
	t_tetri		*tetrimino;
	uint8_t		c;
	uint8_t		void_flag;

	(void)tetriminoes;

	tetrimino = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	if (!tetrimino)
		return ((t_tetri *)errors("mallocation issue", 0));
	c = 0;
	void_flag = (uint8_t)(-1);
	while (1)
	{
		tetrimino_str += tetrimino_str[c] == '\n';
		if (tetrimino_str[c] == '#')
		{
			if (void_flag == (uint8_t)(-1))
				void_flag = c;
			tetrimino->binary_tetrimino |= 1 << void_flag;
		}
		if (++c >= TETRIMINO_LEN)
			break ;
		tetrimino->binary_tetrimino <<= 1;
	}
	return (match_binary_tetrimino(tetrimino));
}


/*
t_tetrimino	*convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_str)
{
	t_tetrimino		*tetrimino;
	uint8_t			c;
	uint8_t			void_flag;
	uint8_t			void_count;
	uint8_t			line_voids;

	(void)tetriminoes;

	tetrimino = (t_tetrimino *)ft_memalloc(sizeof(t_tetrimino));
	if (!tetrimino)
		return ((t_tetrimino *)errors("mallocation issue", 0));
	c = 0;
	void_flag = 1;
	void_count = 0;
	line_voids = 0;
	while (c < TETRIMINO_LEN)
	{
		if (tetrimino_str[c] == '\n' && tetrimino_str++ && voids(line_voids))
			line_voids = 0;
		if (tetrimino_str[c] == '#')
		{
			void_flag = 0;
			tetrimino->binary_tetrimino |= 1;
		}
		else
			line_voids++;
		if (void_flag)
			void_count++;
		tetrimino->binary_tetrimino <<= 1;
		c++;
	}
	if (void_count > 4)
	{
		tetrimino->voids = void_count % 4;
		tetrimino->binary_tetrimino <<= (void_count - void_count % 4);
	}
	else
		tetrimino->binary_tetrimino <<= voids[0];
	return (tetrimino);
}
*/


