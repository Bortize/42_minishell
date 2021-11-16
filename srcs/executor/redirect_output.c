/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:01:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/26 15:54:13 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
#include <unistd.h>

/*
**	Sequentially open/close all output redirected to stdout, leaving only the
**	last one open and redirected.
**	The type **should** only be either redir_out or redir_out_append.
**	Return either the opened FD, or -1 if something is wrong.
*/

int	redirect_output(t_list *out_lst)
{
	int	fd;
	t_redirect *redir_data;

	fd = STDOUT_FILENO;
	while (out_lst)
	{
		redir_data = out_lst->content;
		out_lst = out_lst->next;
		close(fd);
		fd = -1;
		if (redir_data->type == redir_out_append)
			fd = open(redir_data->text, O_WRONLY | O_CREAT | O_APPEND, 0666);
		else if (redir_data->type == redir_out)
			fd = open(redir_data->text, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
		{
			write(2, "lolok", 5);
			perror(redir_data->text);
			return (-1);
		}
	}
	return (fd);
}
