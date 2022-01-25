
#include "fillit.h"

#define TETRIMINO_LEN 16

t_tetrimino		*convert_to_short(t_tetriminoes *tetriminoes, char *tetrimino_str)
{
	t_tetrimino		*tetrimino;
	uint8_t			c;
	uint8_t         void_flag;
	uint8_t         void_count;
	uint8_t         voids[2];

	(void)tetriminoes;

	tetrimino = (t_tetrimino *)ft_memalloc(sizeof(t_tetrimino));
	if (!tetrimino)
		return ((t_tetrimino *)errors("mallocation issue", 0));
	c = 0;
	void_flag = 1;
	void_count = 0;
    voids[0] = (uint8_t)(-1); // 0b11111111 --> as unsigned == 255
    voids[1] = 0;
	while (c < TETRIMINO_LEN)
	{
		if (tetrimino_str[c] == '\n' && tetrimino_str++ && voids[1] < voids[0])
               voids[0] = voids[1];
		if (tetrimino_str[c] == '#')
		{
			void_flag = 0;
			tetrimino->binary_tetrimino |= 1;
		}
		else
		    voids[1]++;
		if (void_flag)
			void_count++;
	    tetrimino->binary_tetrimino <<= 1;
		c++;
	}
	tetrimino->voids = void_count % 4;
	tetrimino->binary_tetrimino <<= (void_count - void_count % 4);
	return (tetrimino);
}





