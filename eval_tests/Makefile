# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 17:13:25 by thakala           #+#    #+#              #
#    Updated: 2022/02/02 20:30:48 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
	display_current_solution

SOURCES = ${FILES:=.c}
SRC_DIR = sources
SOURCES := $(foreach s, $(SOURCES), $(SRC_DIR)/$(s))

OBJECTS = ${FILES:=.o}
OBJ_DIR = objects
OBJECTS := $(foreach o, $(OBJECTS), $(OBJ_DIR)/$(o))
OBJECTS_DEBUG = $(foreach o, $(FILES), $(OBJ_DIR)/$(o)$(DBGGSUFFIX).o)

FILLIT_FILES = \
	get_tetriminoes \
	convert_to_short \
	bitarray \
	bitarrset \
	bitarrcheck \
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
FILLIT_SOURCES_DIR = $(FILLIT_DIR)/fillit_sources
FILLIT_DEBUG_DIR = $(FILLIT_DIR)/fillit-debug
FILLIT_OBJECTS_DIR = $(FILLIT_SOURCES_DIR)/objects
FILLIT_OBJECTS_CWD = \
	$(foreach ff, $(FILLIT_FILES), $(FILLIT_OBJECTS_DIR)/$(ff).o)
FILLIT_OBJECTS_IN_FILLIT_DIR = \
	${FILLIT_FILES:=.o}
FILLIT_DEBUG_OBJECTS_IN_FILLIT_DEBUG_DIR = \
	$(foreach ff, $(FILLIT_FILES), $(ff)$(DBGGSUFFIX).o)
FILLIT_DEBUG_OBJECTS_CWD = \
	$(foreach ff, $(FILLIT_FILES), $(FILLIT_DEBUG_DIR)/$(ff)$(DBGGSUFFIX).o)
FILLIT_INCLUDES = $(FILLIT_SOURCES_DIR)
LIBFT_DIR = ../libft
LIBFT_LIB = libft.a
LIBFT_RULE_IN_FILLIT = libft
LIBFT_INCLUDES = $(LIBFT_DIR)

CC = clang
CFLAGS = -Wall -Wextra -Werror
DBGGFLAGS = $(CFLAGS) -g -Wconversion

DISPLAY_CURRENT_SOLUTION_DEPENDENCIES = \
	$(LIBFT_RULE_IN_FILLIT) \
	$(FILLIT_OBJECTS_IN_FILLIT_DIR) \
	$(OBJ_DIR)/display_current_solution.o

DISPLAY_CURRENT_SOLUTION_DEBUG_DEPENDENCIES = \
	$(LIBFT_RULE_IN_FILLIT) \
	$(FILLIT_DEBUG_OBJECTS_IN_FILLIT_DEBUG_DIR) \
	$(OBJ_DIR)/display_current_solution$(DBGGSUFFIX).o

all: $(OBJECTS) $(FILLIT_DEBUG_OBJECTS_IN_FILLIT_DEBUG_DIR)
	echo "all rule called"

$(OBJECTS): $(SOURCES) | directories
	echo "object rule called"
	$(CC) $(CFLAGS) -o $@ -c $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.c, $@) \
		-I $(FILLIT_INCLUDES) \
		-I $(LIBFT_INCLUDES)

$(OBJECTS_DEBUG): $(SOURCES) | directories
	echo "object rule called"
	$(CC) $(DBGGFLAGS) -o $@ -c $(patsubst $(OBJ_DIR)/%$(DBGGSUFFIX).o, $(SRC_DIR)/%.c, $@) \
		-I $(FILLIT_INCLUDES) \
		-I $(LIBFT_INCLUDES)

$(FILLIT_DEBUG_OBJECTS_IN_FILLIT_DEBUG_DIR):
	echo "fillit debug object rule called"
	make -C $(FILLIT_DIR) $@

$(LIBFT_RULE_IN_FILLIT):
	make -C $(FILLIT_DIR) $@

display_current_solution: $(OBJ_DIR)/display_current_solution.o | directories
	$(CC) $(CFLAGS) -o $@.out

display_current_solution$(DBGGSUFFIX): $(DISPLAY_CURRENT_SOLUTION_DEBUG_DEPENDENCIES) | directories
	$(CC) $(DBGGFLAGS) -o $@.out \
		$(FILLIT_DEBUG_OBJECTS_CWD) \
		$(patsubst %, $(OBJ_DIR)/%.o, $@)	\
		-I $(FILLIT_INCLUDES) \
		$(LIBFT_DIR)/$(LIBFT_LIB)

directories:
	echo "directories order-only rule called"
	mkdir -p $(OBJ_DIR)

template:
	echo -n "$(FILLIT_DEBUG_OBJECTS_IN_FILLIT_DEBUG_DIR)"

.PHONY: all \
	display_current_solution \
	directories \
	template
