# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/08/27 21:19:58 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs

NAME=minishell

SRCS:=
SRCS+= minishell.c
SRCS+= split_in_cmds.c
SRCS+= tokenize_cmd.c
SRCS+= is_delimiter.c
SRCS+= is_space.c
SRCS+= count_spaces.c
SRCS+= count_until_repeat.c
#SRCS+= del_token_all.c
#SRCS+= add_token.c
#SRCS+= read_variable.c

CC=clang
CFLAGS=-Wall -Werror -Wextra -I. -I./headers -g

OBJS=$(SRCS:.c=.o)

LDFLAGS=-Llibft
LDLIBS=-lreadline -lft

.PHONY: all clean fclean re

all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(OBJS) libft/libft.a

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

