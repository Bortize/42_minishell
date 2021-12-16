/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:45:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 21:16:40 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	The execution takes the commands given and executes them.
**	Takes user input for heredocs.
**	Built-ins modify the shell status when called alone, no fork happens.
**	Otherwise a pipeline is created.
*/

void	start_execution(t_list *cmd_lst, t_list **env_lst)
{
	const size_t	cmd_num = ft_lstsize(cmd_lst);
	pid_t			last_pid;
	int				builtin_return;

	if (heredoc(cmd_lst) == 1)
	{
		set_exit_status(1);
		return ;
	}
	builtin_return = -1;
	if (cmd_num == 1)
		builtin_return = builtins(env_lst, ((t_cmd *)cmd_lst->content)->argv);
	if (builtin_return == -1)
	{
		exec_cmd_pipe(cmd_lst, *env_lst, cmd_num, &last_pid);
		wait_children(cmd_num, last_pid);
	}
	else
		set_exit_status((unsigned char)builtin_return);
}
