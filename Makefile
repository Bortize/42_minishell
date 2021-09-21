# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/09/21 12:59:17 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.h headers
vpath %.o objects

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
#SRCS+= read_variable.c

CC=clang
CFLAGS=-Wall -Werror -Wextra -I. -I./headers -g

OBJS=$(SRCS:.c=.o)
ODIR=objects

LDFLAGS=-L./libft
LDLIBS=-lreadline -lft

.PHONY: all clean fclean re objects

all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(addprefix $(ODIR)/,$(OBJS)) -o $@

%.o : %.c minishell.h objects
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $< -c -o $(ODIR)/$@

clean :
	@rm -rf $(OBJS)

relibs :
	make re -C libft

fclean : clean
	@rm -rf $(NAME)

re : fclean all

