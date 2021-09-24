# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/09/24 20:04:30 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.h headers
vpath %.o objects

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
#SRCS+= read_variable.c

CC=clang
CFLAGS=-Wall -Werror -Wextra -I. -I./headers -g

OBJS=$(SRCS:.c=.o)
ODIR=objects

TEST=$(filter minishell, $(OBJS))

LDFLAGS=-Llibft
LDLIBS=-lreadline -lft

.PHONY: all clean fclean re test

all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(addprefix $(ODIR)/,$(OBJS)) -o $@

%.o : %.c minishell.h objects
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $< -c -o $(ODIR)/$@

test : $(TEST) syntax_tester.o libft/libft.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(TEST) syntax_tester.o -o test

clean :
	@rm -rf $(OBJS)

relibs :
	make re -C libft

fclean : clean
	@rm -rf $(NAME)

re : fclean all

