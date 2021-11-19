/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:34:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 21:52:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
#include <unistd.h>

/*
**	Sequentially open/close all inputs redirected to stdin, leaving only the
**	last one open and redirected.
**	The type **should** only be either redir_in or here_doc.
**	Return either the opened FD, or -1 if something is wrong.
*/

//TODO Heredoc temp files missing, ignore them for now.
int	redirect_input(t_list *in_lst)
{
	int			fd;
	t_redirect	*redir_data;

	fd = STDIN_FILENO;
	while (in_lst)
	{
		redir_data = in_lst->content;
		in_lst = in_lst->next;
		close(fd);
		if (redir_data->type == redir_in)
			fd = open(redir_data->text, O_RDONLY);
		else if (redir_data->type == here_doc)
			continue ; //TODO HERE-DOC stuff.
		if (fd == -1 || dup2(fd, STDIN_FILENO) == -1)
		{
			perror(redir_data->text);
			return (-1);
		}
	}
	return (fd);
}
