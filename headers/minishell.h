/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/14 22:07:08 by vicmarti         ###   ########.fr       */
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
# include <string.h>
# include <limits.h>
# include <errno.h>

# define READ_END 0
# define WRITE_END 1

pid_t	g_pidv[CHILD_MAX];
int		g_interrupted;
int		g_heredoc;
int		g_builtin;
int		g_child;
int		g_status;

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
	char	*heredoc_filename;
	t_list	*arg;
	t_list	*lst_redir_in;
	t_list	*lst_redir_out;
}				t_cmd;

typedef struct s_env_var
{
	char	*key;
	char	*value;
}			t_env_var;

//Builtins
void	print_error(char *str);
int		builtins(t_list **env_lst, char **str_args);
//void	builtins_echo(char **argv);FIXME
int		builtint_pwd(char *str);
int		builtins_env(t_list *env_lst);
int		builtins_exit(char **argv);
int		builtins_unset(t_list **env_lst, char **str_args);
void	builtins_env_list(char **argv, char **env);
int		builtins_cd(char **arg, t_list *env_lst);
int		update_shlvl(t_list *env_lst);

//Parser
int		is_delimiter(char c);
int		is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);
size_t	read_variable(char *text);
void	split_in_cmds(char *line, t_list **last_cmd, t_list *env_lst);
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node, t_list *env_lst);
t_list	*tokenize_expansions(char *line, t_list *env);
char	*expand_str(char *str, t_list *env_lst);
void	free_cmd(void *elem);
void	free_redirect(void *elem);
void	print_cmd(void *elem);
void	print_redir(void *elem);
int		string_validator(char *line);
int		string_validator_pipes(char *line);
int		string_validator_quotes(char *line);
int		string_validator_redir(char *line);

//Signals
void	set_msh_signals(void);
void	sig_handler(int signum);

//Executor
void	start_execution(t_list *cmd_lst, t_list **env_lst);
char	*get_path(char *file, char *path_env);
int		redirect_input(t_list *in_lst, char *heredoc_file);
int		exec_cmd_pipe(t_list *cmd_lst, t_list *env_lst, size_t cmdn);
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
char	*ft_strcat_lst(t_list *str_lst);

//Environment
void	*env_var_new(char *key_str, char *value_str);
void	env_var_add(t_list **env_lst, char *key, char *value);
void	env_var_add_str(char *line_env, t_list **list);
void	env_var_new_value(t_env_var *node, char *new_val);
void	env_var_delete(t_env_var *var);
int		env_var_cmp(void *elem1, void *elem2);
t_list	*build_env_lst(char **env);
t_env_var	*env_var_find(t_list *env_lst, char *key);
//TODO Name
char	*get_current_path(t_list *env_lst, char *str);
char	*set_key_value(t_list *env_lst, char *str, char *search);
//TODO ----
char	*stringify_var(t_env_var *var);
char	**stringify_env(t_list *env);
void	free_env_var(void *ptr);
void	print_env(void *content);
void	print_echo_str(char **str);
int		builtins_export(t_list **env_lst, char **str_args);
size_t	read_variable(char *text);

#endif
