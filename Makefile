# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/07/31 20:38:35 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs

NAME=minishell

SRCS:=
SRCS+= del_token_all.c
SRCS+= add_token.c
SRCS+= minishell.c

CC=clang
CFLAGS=-Wall -Werror -Wextra

OBJS=$(SRCS:.c=.o)

LIBS=-lreadline

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(LIBS) $(OBJS) -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

