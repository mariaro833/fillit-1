# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:43:44 by thakala           #+#    #+#              #
#    Updated: 2022/01/11 15:06:50 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILLIT_DIR = fillit

LIBFT_DIR = libft

CC = clang

CFLAGS = -Wall -Wextra -Werror

FUNCTIONS = \

SOURCES = $(foreach function, $(FUNCTIONS), $(function).c)

OBJECTS = $(foreach function, $(FUNCTIONS), $(function).o)

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

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

fclean:
#	/bin/rm

re: fclean all
