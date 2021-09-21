# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/09/21 12:12:43 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c srcs/environment

NAME=minishell

SRCS:=
SRCS+= minishell.c
SRCS+= split_in_cmds.c
SRCS+= tokenize_cmd.c
SRCS+= print_cmd.c
SRCS+= print_redir.c
SRCS+= free_cmd.c
SRCS+= free_redirect.c
SRCS+= is_delimiter.c
SRCS+= is_space.c
SRCS+= count_spaces.c
SRCS+= count_until_repeat.c
SRCS+= env_var_new.c
SRCS+= env_var_new_value.c
SRCS+= env_var_delete.c
SRCS+= env_var_cmp.c
#SRCS+= read_variable.c

CC=clang
#-O2 or greater uses tail-call optimizations that should make recursion safe
CFLAGS= -O3 -Wall -Werror -Wextra -I. -I./headers -g

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

relibs :
	make re -C libft

fclean : clean
	@rm -rf $(NAME)

re : fclean all

