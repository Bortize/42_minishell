# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/08/03 17:29:04 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs

NAME=minishell

SRCS:=
SRCS+= del_token_all.c
SRCS+= add_token.c
SRCS+= read_variable.c
SRCS+= minishell.c

CC=clang
CFLAGS=-Wall -Werror -Wextra -I. -I./headers

OBJS=$(SRCS:.c=.o)

LDFLAGS=-Llibft
LDLIBS=-lreadline -lft

.PHONY: all clean fclean re

all : $(NAME) libft.a

libft.a :
	make -C libft

$(NAME) : $(OBJS)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

