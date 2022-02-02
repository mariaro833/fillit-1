# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 17:13:25 by thakala           #+#    #+#              #
#    Updated: 2022/02/02 19:39:54 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
	display_current_solution

SOURCES = ${FILES:=.c}
SRC_DIR = sources
SOURCES := $(foreach s, $(SOURCES), $(SRC_DIR)/$(s))

OBJECTS = ${FILES:=.o}
OBJ_DIR = objects
OBJECTS := $(foreach s, $(OBJECTS), $(OBJ_DIR)/$(s))

FILLIT_FILES = \
	get_tetriminoes \
	convert_to_short \
	bitarray \
	bitarrset \
	split_long \
	bitarrunset \
	bitarrzero \
	display \
	fillit \
	pad_short \
	place_alphabet \
	solve \
	link_tetriminoes \
	tetrimino_reference \
	main

DBGGSUFFIX = -debug

FILLIT_DIR = ..
FILLIT_SOURCES_DIR = ../fillit_sources
FILLIT_OBJECTS_DIR = $(FILLIT_SOURCES_DIR)/objects
FILLIT_OBJECTS_CWD = \
	$(foreach ff, $(FILLIT_FILES), $(FILLIT_OBJECTS_DIR)/$(ff).o)
FILLIT_OBJECTS_IN_FILLIT_DIR = \
	 ${FILLIT_FILES:=.o}
LIBFT_DIR = ../libft
LIBFT_LIB = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
DBGGFLAGS = -g -Wconversion

DISPLAY_CURRENT_SOLUTION_DEPENDENCIES = \
	$(FILLIT_OBJECTS_IN_FILLIT_DIR) \
	$(OBJ_DIR)/display_current_solution.o

all: $(OBJECTS) $(FILLIT_OBJECTS_IN_FILLIT_DIR)
	echo "all rule called"

$(OBJECTS): $(SOURCES) | directories
	echo "object rule called"
	$(CC) $(CFLAGS) -o $@ -c $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.c, $@)

$(FILLIT_OBJECTS_IN_FILLIT_DIR):
	echo "fillit object rule called"
	make -C $(FILLIT_DIR) $@


display_current_solution: $(OBJ_DIR)/display_current_solution.o | directories
	$(CC) $(CFLAGS) -o $@.out


display_current_solution$(DBGGSUFFIX): $(DISPLAY_CURRENT_SOLUTION_DEPENDENCIES) | directories
	$(CC) $(DBGGFLAGS) -o $@.out \
		$(FILLIT_OBJECTS_CWD) \
		$(patsubst %$(DBGGSUFFIX), %.o, $@)

directories:
	echo "directories order-only rule called"
	mkdir -p $(OBJ_DIR)

template:
	echo -n "$(SOURCES)"

.PHONY: all \
	display_current_solution \
	directories \
	template
