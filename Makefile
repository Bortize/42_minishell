# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 18:30:43 by bgomez-r          #+#    #+#              #
#    Updated: 2021/12/18 22:34:37 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ODIR=objects

vpath %.c srcs
vpath %.c srcs/builtins
vpath %.c srcs/environment
vpath %.c srcs/executor
vpath %.c srcs/signals
vpath %.c srcs/parser
vpath %.h headers
vpath %.o $(ODIR)
vpath %.o.dbg $(ODIR)

NAME=minishell
DBG_NAME=debug

SRCS:=
SRCS+= minishell.c
SRCS+= utils.c
SRCS+= error.c
SRCS+= print_cmd.c
SRCS+= print_redir.c
SRCS+= free_cmd.c
SRCS+= free_redirect.c
SRCS+= update_shlvl.c

#Parser
SRCS+= split_in_cmds.c
SRCS+= tokenize_cmd.c
SRCS+= tokenize_expansions.c
SRCS+= expand_str.c
SRCS+= is_delimiter.c
SRCS+= is_space.c
SRCS+= count_spaces.c
SRCS+= count_until_repeat.c
SRCS+= string_validator.c
SRCS+= string_validator_pipes.c
SRCS+= string_validator_quotes.c
SRCS+= string_validator_redir.c
SRCS+= read_variable.c
SRCS+= expand_str.c

#Signals
SRCS+= sig_handler.c
SRCS+= set_msh_signals.c

#Executor
SRCS+= start_execution.c
SRCS+= run_single_builtin.c
SRCS+= exec_cmd_pipe.c
SRCS+= set_redir.c
SRCS+= redirect_input.c
SRCS+= redirect_output.c
SRCS+= wait_children.c
SRCS+= get_path.c
SRCS+= pipes.c
SRCS+= heredoc.c

#Env
SRCS+= env_var_new.c
SRCS+= env_var_new_value.c
SRCS+= env_var_add.c
SRCS+= env_var_add_str.c
SRCS+= env_var_delete.c
SRCS+= env_var_cmp.c
SRCS+= env_var_find.c
SRCS+= stringify_var.c
SRCS+= stringify_env.c

#Builtins
SRCS+= get_builtin.c
SRCS+= builtins_pwd.c
SRCS+= builtins_env.c
SRCS+= builtins_unset.c
SRCS+= builtins_exit.c
SRCS+= builtins_cd.c
SRCS+= builtins_echo.c
SRCS+= build_env_lst.c
SRCS+= free_env_var.c
SRCS+= print_env.c
SRCS+= builtins_export.c
SRCS+= search_in_list.c

#Utils
SRCS+= ft_lst_remove_if.c
SRCS+= ft_strcat_lst.c
SRCS+= perror_and_exit.c
SRCS+= set_exit_status.c

CC=clang
#-O2 or greater uses tail-call optimizations that should make recursion safe
CFLAGS= -Wall -Werror -Wextra -I. -I./headers -I./readline/include -O2
DBG_FLAGS= -Wall -Werror -Wextra -I. -I./headers -I./readline/include -g -fsanitize=address

OBJS=$(SRCS:.c=.o)
DBG_OBJS=$(SRCS:.c=.o.dbg)

TEST=$(filter minishell, $(OBJS))

LDFLAGS=-Llibft -Lreadline/lib
LDLIBS=-lreadline -ltermcap -lft

.PHONY: all clean fclean re test relibs

all : $(NAME)

libft/libft.a :
	git submodule update --init
	make -C libft

$(NAME) : $(OBJS) libft/libft.a
	git submodule update --init
	$(CC) $(LDFLAGS) $(LDLIBS) $(addprefix $(ODIR)/,$(OBJS)) -o $@

%.o.dbg : %.c minishell.h
	mkdir -p $(ODIR)
	$(CC) $(DBG_FLAGS) $< -c -o $(ODIR)/$@
	ctags -a $<

%.o : %.c minishell.h
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $< -c -o $(ODIR)/$@
	ctags -a $<

test : $(TEST) syntax_tester.o libft/libft.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(TEST) syntax_tester.o -o test

$(DBG_NAME) : $(DBG_OBJS) libft/libft.a
	git submodule update --init
	$(CC) $(LDFLAGS) -fsanitize=address $(LDLIBS) $(addprefix $(ODIR)/,$(DBG_OBJS)) -o $(DBG_NAME)

clean :
	rm -rf $(ODIR) $(NAME).dbg

relibs :
	make re -C libft

fclean : clean
	rm -rf $(NAME)

re : fclean all

