/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:45:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/23 23:26:18 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	The execution takes the commands given and executes them.
**	Built-ins modify the shell status when called alone, no fork happens.
**	Otherwise a pipeline is created.
*/
void	start_execution(t_list *cmd_lst, t_list *env_lst)
{
	const size_t	cmd_num = ft_lstsize(cmd_lst);

	g_builtin = 0;
	if (cmd_num == 1)
		//TODO do something about exit status
		builtins(env_lst, ((t_cmd *)cmd_lst->content)->argv);
	if (g_builtin == 0)
	{
		exec_cmd_pipe(cmd_lst, env_lst, cmd_num);
		wait_children(cmd_num);
	}
	g_builtin = 0;
}
