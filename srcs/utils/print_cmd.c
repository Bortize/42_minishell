/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 03:05:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 20:25:52 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	putendl_wrapper(void *str)
{
	ft_putendl_fd(str, 1);
}

void	put_str_arr(char **str_arr, int fd)
{
	if (!str_arr)
		return ;
	while (*str_arr)
	{
		ft_putendl_fd(*str_arr, fd);
		str_arr++;
	}
}

void	print_cmd(void *elem)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)elem;
	printf("\nArguments:\n");
	ft_lstiter(cmd->arg, putendl_wrapper);
	printf("Argument Vector:\n");
	put_str_arr(cmd->argv, 1);
	printf("In redirections:\n");
	ft_lstiter(cmd->lst_redir_in, print_redir);
	printf("Out redirections:\n");
	ft_lstiter(cmd->lst_redir_out, print_redir);
}
