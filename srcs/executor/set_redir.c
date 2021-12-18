/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:58:13 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/18 19:05:50 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>

int	set_redir(t_behavior type, char *filename, int redir_dest)
{
	int	fd;

	fd = -1;
	if (type == redir_in || type == here_doc)
		fd = open(filename, O_RDONLY);
	else if (type == redir_out)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (type == redir_out_append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1 || dup2(fd, redir_dest) == -1)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

