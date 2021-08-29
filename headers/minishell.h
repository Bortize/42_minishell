/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/29 03:08:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdlib.h>

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
	char			*cmd;
	char			*arg;
	t_list			*lst_redir_in;
	t_list			*lst_redir_out;
}			t_cmd;

int	is_delimiter(char c);
int	is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);

t_list	*split_in_cmds(char *line);
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node);
void	free_cmd(void *elem);
void	free_redirect(void *elem);
void	print_cmds(t_list *cmd_lst);
#endif
