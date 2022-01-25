#gcc -g -Wall -Wextra -Werror \
gcc -g \
	convert_to_short_plan.c \
	errors.c \
	get_tetriminoes.c \
	tetrimino_reference.c \
	../../fillit-testset/sources/helpers/long_to_ascii_binary.c \
	../../fillit-testset/sources/helpers/auxiliary/debug_error.c \
	-I. \
	-I../../fillit-testset/sources/helpers/includes/ \
	-I../libft-debug/ \
	../libft-debug/libft.a
