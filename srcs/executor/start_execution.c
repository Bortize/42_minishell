/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:45:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/24 14:27:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#include <fcntl.h>
#include <unistd.h>

//TODO Temporary just to leave way top the builtins once thet come.
static int	is_builtin(void)
{
	return (0);
}

static void	run_builtin(void)
{
	return ;
}
//TODO unfleshed out
char	*get_tmp_filename(void)
{
	char	*filename;

	filename = ft_strdup("msh_heredoc.tmp");
	return (filename);
}

int	read_user_input(t_cmd *cmd, char *delimiter, void *has_next)
{
	char	*line;
	int		fd;

	fd = -1;
	if (has_next == NULL)
	{
		cmd->heredoc_filename = get_tmp_filename();
		fd = open(cmd->heredoc_filename, O_TRUNC | O_CREAT | O_WRONLY, 0600);
		if (fd == -1)
			return (1);
	}
	line = readline("<< ");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("<< ");
	}
	free(line);
	if (!line)
		ft_putstr_fd("HEREDOC: Reached EOF", 2);
	close(fd);
	return (0);
}


int	read_all_heredocs(t_cmd *cmd)
{
	t_list		*lst_redir_in;
	t_redirect	*redir_in;

	lst_redir_in = cmd->lst_redir_in;
	while (lst_redir_in)
	{
		redir_in = lst_redir_in->content;
		if (redir_in->type == here_doc)
		{
			if (read_user_input(cmd, redir_in->text, lst_redir_in->next) == -1)
				return (1);
		}
		lst_redir_in = lst_redir_in->next;
	}
	return (0);
}


int	heredoc(t_list *cmd_lst)
{
	while (cmd_lst)
	{
		if (read_all_heredocs(cmd_lst->content))
			return (1);
		cmd_lst = cmd_lst->next;
	}
	return (0);
}

/*
**	The execution takes the commands given and executes them.
**	Takes user input for heredocs (TODO ? do it before calling execution)
**	Built-ins modify the shell status when called alone, no fork happens.
**	Otherwise a pipeline is created.
*/

void	start_execution(t_list *cmd_lst)
{
	const size_t	cmd_num = ft_lstsize(cmd_lst);

	heredoc(cmd_lst);
	if (cmd_num == 1 && is_builtin())
		run_builtin();
	else
	{
		exec_cmd_pipe(cmd_lst, cmd_num);
		wait_children(cmd_num);
	}
}
