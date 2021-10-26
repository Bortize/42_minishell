/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:34:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/26 15:38:24 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
#include <unistd.h>

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
		fd = open(redir_data->text, O_RDONLY);
		if (fd == -1 || dup2(fd, STDIN_FILENO == -1))
		{
			perror(redir_data->text);
			return (-1);
		}
	}
	return (fd);
}
