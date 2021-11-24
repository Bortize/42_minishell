/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/24 14:26:19 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
//Readline dependency
//Always call to stdio before readline.
# include <stdio.h>
# include "readline/readline.h"
# include "readline/history.h"
//END Readline
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <string.h>// For builtins_pwd.c
# include <limits.h>// For builtins_pwd.c, back_home.c
# include <errno.h>

# define READ_END 0
# define WRITE_END 1

pid_t	g_pidv[CHILD_MAX];
int		g_interrupted;
int		g_builtin;

typedef enum e_behavior
{
	redir_out,
	redir_out_append,
	redir_in,
	here_doc,
	plain
}			t_behavior;

typedef struct s_redirect
{
	char		*text;
	t_behavior	type;
}				t_redirect;

typedef struct s_cmd
{
	char	**argv;
	t_list	*arg;
	t_list	*lst_redir_in;
	t_list	*lst_redir_out;
}				t_cmd;

typedef struct s_env_var
{
	char	*key;
	char	*value;
}			t_env_var;

int		is_delimiter(char c);
int		is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);

void	split_in_cmds(char *line, t_list **last_cmd, t_list *env_lst);
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node);//, t_list *env_lst);
void	free_cmd(void *elem);
void	free_redirect(void *elem);
void	print_cmd(void *elem);
void	print_redir(void *elem);
int		string_validator(char *line);
int		string_validator_pipes(char *line);
void	print_error(char *str);
void	builtins(/*t_list *cmd_lst, */t_list *env_lst, char **str_args);
void	builtint_echo(char **argv);
void	builtint_pwd(char *str);
t_list	*builtins_env(char **env);
void	builtins_env_list(char **argv, char **env);

//Signals
void	set_msh_signals(void);
void	sig_handler(int signum);

//Executor
void	start_execution(t_list *cmd_lst, t_list *env_lst);
char	*get_path(char *file, char *path_env);
int		exec_cmd_pipe(t_list *cmd_lst, t_list *env_lst, size_t cmdn);
int		redirect_input(t_list *in_lst);
int		redirect_output(t_list *out_lst);
void	wait_children(size_t cmd_num);
int		create_pipes(int pipev[CHILD_MAX - 1][2], size_t cmd_count);
int		configure_pipeline(int cmd_index, int cmd_count, int (*pipev)[2]);
void	clean_pipes(int pipev[CHILD_MAX - 1][2], int size);

//Utils  (?)
char	**build_str_arr(t_list *str_lst);
void	ft_free_arr(void **ptr_arr);
t_list	*ft_lst_at(t_list *lst, size_t pos);
t_list	*ft_lst_find(t_list *lst, void *data_ref, int (*cmp)(void *, void *));

//Environment
void	*env_var_new(char *key_str, char *value_str);
void	env_var_new_value(t_env_var *node, char *new_val);
void	env_var_delete(t_env_var *var);
int		env_var_cmp(void *elem1, void *elem2);
void	free_env_var(void *ptr);
void	print_env(void *content);
void	print_echo(void *elem);
void	ft_exit(void *elem);
void	print_echo_str(char **str);
void	builtins_cd(char **arg, t_list *env_lst);
void	check_existence_environment(t_list *str);

#endif
