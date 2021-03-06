/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/20 17:41:40 by vicmarti         ###   ########.fr       */
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
# include <sys/errno.h>

# define READ_END 0
# define WRITE_END 1

//We allocate the last byte 0xFF for the program exit status.
# define STS_IS_CHILD 0x100
# define STS_HAS_CHILD 0x300
# define STS_INTERRUPT 0x700

//This indentation is to satisfy Norminette's fickle desires.
//We should report that or open a github issue after we finish.
//All hail Norminette. Praised be its whiskers. Blessed be its seat.
int			g_status;

typedef int	(*t_builtin_funcp)(char **, t_list **);

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
t_builtin_funcp	get_builtin(char *str);
void			print_error(char *str);
int				builtins_echo(char **argv, t_list **env_lst);
int				builtins_pwd(char **argv, t_list **env_lst);
int				builtins_env(char **argv, t_list **env_lst);
int				builtins_exit(char **argv, t_list **env_lst);
int				builtins_unset(char **argv, t_list **env_lst);
int				builtins_cd(char **arg, t_list **env_lst);
int				builtins_export(char **str_args, t_list **env_lst);

//Parser
int				parse_line(char *line, t_list **cmd_lst, t_list *env_lst);
int				is_delimiter(char c);
int				is_space(char c);
size_t			count_spaces(char *line);
size_t			count_until_repeat(char *line);
size_t			read_variable(char *text);
void			split_in_cmds(char *line, t_list **last_cmd, t_list *env_lst);
void			tokenize_cmd(char *cmd_txt, t_cmd *cmd_node, t_list *env_lst);
void			tokenize_expansions(t_list **tk_lst, char *line, t_list *env);
char			*expand_str(char *str, t_list *env_lst);
void			free_cmd(void *elem);
void			free_redirect(void *elem);
void			print_cmd(void *elem);
void			print_redir(void *elem);
int				string_validator(char *line);
int				string_validator_pipes(char *line);
int				string_validator_quotes(char *line);
int				string_validator_redir(char *line);

//Signals
void			set_msh_signals(void);
void			sig_handler(int signum);

//Executor
void			start_execution(t_list *cmd_lst, t_list **env_lst);
char			*get_path(char *file, char *path_env);
void			run_single_builtin(t_builtin_funcp builtin, t_cmd *cmd,
					t_list **env_lst);
void			exec_cmd_pipe(t_list *cmd_lst, t_list *env_lst, size_t cmdn,
					pid_t *last_pid);
int				set_redir(t_behavior type, char *filename, int redir_dest);
int				redirect_input(t_list *in_lst, char *heredoc_file);
int				redirect_output(t_list *out_lst);
int				heredoc(t_list *cmd_lst);
void			wait_children(size_t cmd_num, pid_t last_pid);
int				create_pipes(int pipev[CHILD_MAX - 1][2], size_t cmd_count);
int				configure_pipeline(int cmd_index, int cmd_count,
					int (*pipev)[2]);
void			clean_pipes(int pipev[CHILD_MAX - 1][2], int size);
void			set_exit_status(int value);

//Utils
char			**build_str_arr(t_list *str_lst);
void			ft_free_arr(void **ptr_arr);
t_list			*ft_lst_at(t_list *lst, size_t pos);
t_list			*ft_lst_find(t_list *lst, void *data_ref,
					int (*cmp)(void *, void *));
void			ft_lst_remove_if(t_list **lst, void *data_ref, int (*cmp)(),
					void (*free_fun)(void *));
char			*ft_strcat_lst(t_list *str_lst);
size_t			ft_strlen_matrix(char **str);
void			perror_and_exit(char *msg, int exit_status);

//Environment
void			*env_var_new(char *key_str, char *value_str);
void			env_var_add(t_list **env_lst, char *key, char *value);
void			env_var_add_str(char *line_env, t_list **list);
void			env_var_new_value(t_env_var *node, char *new_val);
void			env_var_delete(t_env_var *var);
int				env_var_cmp(void *elem1, void *elem2);
char			**env_lst_to_array(t_list *str_lst);
t_list			*build_env_lst(char **env);
t_env_var		*env_var_find(t_list *env_lst, char *key);
int				update_shlvl(t_list *env_lst);
char			*get_current_path(t_list *env_lst, char *str);
char			*set_key_value(t_list *env_lst, char *str, char *search);
char			*stringify_var(t_env_var *var);
char			**stringify_env(t_list *env);
void			free_env_var(void *ptr);
void			print_env(void *content);
void			print_echo_str(char **str);
size_t			read_variable(char *text);

#endif
