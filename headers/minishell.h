/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/24 14:15:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

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

typedef struct	s_cmd
{
	char			*cmd;
	char			*arg;
	t_list			*lst_redir_in;
	t_list			*lst_redir_out;
}				t_cmd;

int		is_delimiter(char c);
int		is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);

void	split_in_cmds(char *line, t_list **last_cmd);
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node);
void	free_cmd(void *elem);
void	free_redirect(void *elem);
void	print_cmd(void *elem);
void	print_redir(void *elem);
int		string_validator(char *line);
int		string_validator_pipes(char *line);
void	print_error(char *str);

#endif
