/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:34:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 20:49:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
#include <unistd.h>

/*
**	Sequentially open/close all inputs redirected to stdin, leaving only the
**	last one open and redirected.
**	Here-Doc file is a previously created user input file.
**	The type **should** only be either redir_in or here_doc.
**	Return either the opened FD, or -1 if something is wrong.
*/

void	redirect_input(t_list *in_lst, char *heredoc_file)
{
	int			heredoc_fd;
	int			fd;
	t_redirect	*redir_data;

	heredoc_fd = open(heredoc_file, O_RDONLY);
	fd = STDIN_FILENO;
	while (in_lst)
	{
		redir_data = in_lst->content;
		in_lst = in_lst->next;
		if (fd != heredoc_fd)
			close(fd);
		if (redir_data->type == redir_in)
		{
			fd = open(redir_data->text, O_RDONLY);
			if (fd == -1)
				perror_and_exit(redir_data->text, errno);
		}
		else if (redir_data->type == here_doc)
			fd = heredoc_fd;
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror_and_exit(redir_data->text, errno);
}
