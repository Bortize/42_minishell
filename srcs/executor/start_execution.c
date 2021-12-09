/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:45:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/09 12:39:59 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//TODO  in iont's owm file dummy
#include <fcntl.h>
#include <unistd.h>

static void	find_available(char *name)
{
	const int	mode = F_OK;
	int			i;

	while (access(name, mode) == 0)
	{
		i = 0;
		while (name[i] == '9')
			name[i++] = '0';
		if (name[i] == '.')
			break ;
		name[i]++;
	}
}
//TODO unfleshed out
char	*get_tmp_filename(void)
{
	char	*filename;
	
	filename = ft_strdup("00000000000000.tmp");
	find_available(filename);
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
	while (!g_interrupted && line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("<< ");
	}
	free(line);
	if (!line)
		ft_putstr_fd("HEREDOC: Reached EOF\n", 2);
	close(fd);
	if (g_interrupted)
		return (1);
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
			if (read_user_input(cmd, redir_in->text, lst_redir_in->next) == 1)
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

void	start_execution(t_list *cmd_lst, t_list **env_lst)
{
	const size_t	cmd_num = ft_lstsize(cmd_lst);

	if (heredoc(cmd_lst) == 1)
		return ;
	g_builtin = 0;
	if (cmd_num == 1)
		//TODO do something about exit status
		builtins(env_lst, ((t_cmd *)cmd_lst->content)->argv);
	if (g_builtin == 0)
	{
		exec_cmd_pipe(cmd_lst, *env_lst, cmd_num);
		wait_children(cmd_num);
	}
	g_builtin = 0;
}
