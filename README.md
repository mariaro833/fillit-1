# FILLIT

<details open><summary>ABOUT FILLIT PROJECT</summary>

Fillit is the last mandatory for everyone algorithmic project at HIVE Helsinki programming school.

The aim of the project is to Find the smallest square that given tetrominos fit into (Hive Helsinki (42) programming school project). It’s needed to create a program that could arrange a set of 1 to 26 tetraminos in the smallest possible square and print the result. Written in C language. 
> [the subject](https://cdn.intra.42.fr/pdf/pdf/6621/fillit.en.pdf) & [a sequential chart](https://github.com/mariaro833/fillit/blob/mrozhnov/fillit-chart.pdf)


<details open><summary>TEAM</summary>

| Name | Lead in: |
| --- | --- |
| Teemu | leader, main thinker and inventor, main programmer |
| Maria | simple functions, documentation, algorithms |

This project was completed with Teemu Hakala and Maria Rozhnova on February 5th, 2022

<details open><summary>HOW IT WORKS? </summary>

First, the file is opened and read in its entirety. Each Tetrimino is checked to make sure it is valid.
We decided to save each Tetrimino as a single string of bits. For this, the convert_to_short function is used.
Then we create a bit array for our future board. We calculate the minimum board size based on the amount of incoming tetriminoes.
Bitarray consists of 64-bit unsigned integers (uint64_t). Each position in the bitarray corresponds to an index.
We also defined all possible tetriminoes as bit strings and initialized them using the tetrimino_reference function.
Then, according to the algorithm, we add each tetrimino to the bitarray.
Since our tetrimino has an initial size of 4X4, we need to match it to the size of the board by padding it with zeroes. This is what [pad_short.c](./fillit_sources/pad_short.c) does.
Then we check for overlap with bitwise AND, &, and if it occurs, move on to the next index.
With the help of the [skip_index](./fillit_sources/solve.c) function, we check if there is enough space to place the tetrimino by comparing the current length and height of the board with the dimensions of the tetrimino.
In the [solve.c](./fillit_sources/solve.c), the algorithm described below is executed, and with the help of [place_alpabet.c](./fillit_sources/alpabet.c), the board is filling with tetriminoes with letter designations. And [fillit.c](./fillit_sources/fillit.c) transfers the resulting solution to [main.c](./fillit_sources/main.c).

> [get_tetriminoes.c](./fillit_sources/get_tetrimino.c):
Checks for the correct size of one square (4x4) (there must be a '\n' at the end).
Checks for only valid characters ('.', '#').
Counts the number of '#' characters (there must be only 4 hashtags)
Checks for '\n' at the end of the file and at the end of each square.

> [convert_to_short.c](./fillit_sources/short.c) 
the function converts the string to a bitstring

> [tetrimino_reference.c](./fillit_sources/tetrimino_reference.c) 
checks if the shape of the tetrimino matches the condition (each hash must touch one side of the other

> [bitarray.c](./mrozhnov/fillit_sources/bitarray.c) 
Allocated the memory for the board


<details open><summary>BACKTRACKING ALGORITHM</summary>

The smallest possible board size is determined by a 2x2 square tetromino. The size depends on the number and shape of tetrominos.

1. Make sure that one piece fits on the board, and if it fits, place it on the first free space on the board. Repeat until the board is full.
2. If the board is full and no solution has been found, remove the last piece placed on the board and try another position. Repeat until all possible positions for all tetrimino bodies have been verified.
3. If all possible board solutions have been tried, increase the board size by one and start by placing the first tetrimino.
