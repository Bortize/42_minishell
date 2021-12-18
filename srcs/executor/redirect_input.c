/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:34:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/18 19:08:53 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	Sequentially open/close all inputs redirected to stdin, leaving only the
**	last one open and redirected.
**	Here-Doc file is a previously created user input file.
**	The type **should** only be either redir_in or here_doc.
**	Return either the opened FD, or -1 if something is wrong.
*/

int	redirect_input(t_list *in_lst, char *heredoc_file)
{
	int			fd;
	t_redirect	*redir_data;

	fd = STDIN_FILENO;
	while (fd != -1 && in_lst)
	{
		close(fd);
		redir_data = in_lst->content;
		in_lst = in_lst->next;
		if (!in_lst && redir_data->type == here_doc)
			fd = set_redir(redir_data->type, heredoc_file, STDIN_FILENO);
		else if (redir_data->type == redir_in)
			fd = set_redir(redir_data->type, redir_data->text, STDIN_FILENO);
	}
	return (fd);
}
