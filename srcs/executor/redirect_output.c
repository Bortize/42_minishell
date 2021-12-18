/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:01:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/18 19:02:42 by vicmarti         ###   ########.fr       */
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
	int			fd;
	t_redirect	*redir_data;

	fd = STDOUT_FILENO;
	while (fd != -1 && out_lst)
	{
		redir_data = out_lst->content;
		out_lst = out_lst->next;
		close(fd);
		fd = -1;
		if (redir_data->type == redir_out_append)
			fd = set_redir(redir_data->type, redir_data->text, STDOUT_FILENO);
		else if (redir_data->type == redir_out)
			fd = set_redir(redir_data->type, redir_data->text, STDOUT_FILENO);
	}
	return (fd);
}
