# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:43:44 by thakala           #+#    #+#              #
#    Updated: 2022/01/26 13:45:15 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILLIT_DIR = fillit

LIBFT = libft

LIBFT_DIR = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FUNCTIONS = \
	bitarray \
	bitarrset \
	bitarrunset \
	bitarrzero \
	convert_to_short \
	display \
	fillit \
	get_tetriminoes \
	pad_short \
	place_alphabet \
	solve \
	split_long \
	tetrimino_reference

INCLUDE_DIRS = $(FILLIT_DIR) $(LIBFT_DIR)

SOURCES = $(foreach function, $(FUNCTIONS), $(FILLIT_DIR)/$(function).c)

OBJECTS = $(foreach function, $(FUNCTIONS), $(function).o)

OBJ_DIR = $(FILLIT_DIR)/objects

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(foreach o, $^, $(OBJ_DIR)/$(o)) -o $@ \
		-L$(LIBFT_DIR) -lft

$(OBJECTS): $(SOURCES) | directories
	$(CC) $(CFLAGS) -c $(patsubst %.o, $(FILLIT_DIR)/%.c, $@) -o $(OBJ_DIR)/$@ \
		$(foreach i, $(INCLUDE_DIRS), -I$(i))

directories:
	mkdir -p $(OBJ_DIR)

## BEGIN DEBUG
#
DBGGFLAGS = -g $(CFLAGS) -Wconversion

DBGGSUFFIX = -debug

DBGG_DIR = $(NAME)-debug

OBJECTS_DEBUG = $(foreach function, $(FUNCTIONS), $(function)$(DBGGSUFFIX).o)

debug: $(NAME)$(DBGGSUFFIX) | debug-dir
	$(CC) $(DBFLAGS) $(OBJECTS_DEBUG) -o $(DBGG_DIR)/$(NAME)$(DBGGSUFFIX)

debug-dir:
	@mkdir -p $(DBGG_DIR)

$(NAME)$(DBGGSUFFIX): $(OBJECTS_DEBUG)

$(OBJECTS_DEBUG): $(SOURCES)
	$(CC) $(DBGGFLAGS) -o $(patsubst %$(DBGGSUFFIX).o, %.o, $@)
#
## END DEBUG

clean:
#	/bin/rm
##	make -C libft/ clean

fclean:
#	/bin/rm
##	make -C libft/ fclean

re: fclean all

.PHONY: all $(LIBFT) clean fclean re
