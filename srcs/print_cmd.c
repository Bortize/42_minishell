/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 03:05:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/19 15:52:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	putendl_wrapper(void *str)
{
	ft_putendl_fd(str, 1);
}

//This is meant to be be a logging/debug function.
//TODO Probably better and simpler with lst_map_i.
//TODO Throw it to stderr and help us debug cleaner.
//TODO Just use putstr or something along those lines.

void	print_cmd(void *elem)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)elem;
	printf("Arguments:\n");
	ft_lstiter(cmd->arg, putendl_wrapper);
	printf("In redirections:\n");
	ft_lstiter(cmd->lst_redir_in, print_redir);
	printf("Out redirections:\n");
	ft_lstiter(cmd->lst_redir_out, print_redir);
}
