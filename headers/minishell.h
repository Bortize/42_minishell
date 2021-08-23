/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:56:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/23 22:02:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h> //TODO Vicest: I want to just use write, then delete.

typedef enum e_behavior
{
	redir_out,
	redir_out_append,
	redir_in,
	here_doc,
	plain
}			t_behavior;

//TODO Should we keep all redirections in one place? Mix them?
typedef struct s_cmdlst
{
	struct t_cmdlst	*next;
	char			*cmd;
	char			*arg;
	t_list			*lst_redirs;
	//t_list			*lst_redir_in;
	//t_list			*lst_redir_out;
}			t_cmdlst;

int	is_delimiter(char c);
int	is_space(char c);
size_t	count_spaces(char *line);
size_t	count_until_repeat(char *line);

void	split_in_cmds(char *line);
void	tokenize_cmd(char *cmd_txt);
#endif
