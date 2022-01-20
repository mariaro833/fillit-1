# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 11:42:48 by thakala           #+#    #+#              #
#    Updated: 2022/01/20 10:56:37 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCTIONS = \
	ft_memalloc \
	ft_bzero \
	ft_memset

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

COMP_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(COMP_FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
