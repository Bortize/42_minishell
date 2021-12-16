/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:25:32 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 17:06:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
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

static char	*get_tmp_filename(void)
{
	char	*filename;

	filename = ft_strdup("00000000000000.tmp");
	if (filename)
		find_available(filename);
	return (filename);
}

static int	read_user_input(t_cmd *cmd, char *eof, void *has_next)
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
	while (!(g_status & STS_INTERRUPT) && line && ft_strcmp(line, eof) != 0)
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("<< ");
	}
	if (!line)
		ft_putstr_fd("HEREDOC: Reached EOF\n", 2);
	free(line);
	close(fd);
	if (g_status & STS_INTERRUPT)
		return (1);
	return (0);
}

static int	read_all_heredocs(t_cmd *cmd)
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

