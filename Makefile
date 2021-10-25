# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/10/25 15:38:00 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ODIR=objects

vpath %.c srcs
vpath %.c srcs/environment
vpath %.c srcs/executor
vpath %.h headers
vpath %.o $(ODIR)

NAME=minishell

SRCS:=
SRCS+= minishell.c
SRCS+= error.c
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
SRCS+= string_validator.c
SRCS+= string_validator_pipes.c
SRCS+= exec_cmd_pipe.c
SRCS+= redirect_input.c
SRCS+= env_var_new.c
SRCS+= env_var_new_value.c
SRCS+= env_var_delete.c
SRCS+= env_var_cmp.c
#SRCS+= read_variable.c

SRCS+= build_str_arr.c

CC=clang
#-O2 or greater uses tail-call optimizations that should make recursion safe
CFLAGS= -O3 -Wall -Werror -Wextra -I. -I./headers -g

OBJS=$(SRCS:.c=.o)

TEST=$(filter minishell, $(OBJS))

LDFLAGS=-Llibft
LDLIBS=-lreadline -lft

.PHONY: all clean fclean re test relibs

all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(addprefix $(ODIR)/,$(OBJS)) -o $@

%.o : %.c minishell.h
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $< -c -o $(ODIR)/$@

test : $(TEST) syntax_tester.o libft/libft.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(TEST) syntax_tester.o -o test

clean :
	@rm -rf $(ODIR)

relibs :
	make re -C libft

fclean : clean
	@rm -rf $(NAME)

re : fclean all

