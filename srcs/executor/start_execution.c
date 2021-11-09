/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:45:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/08 15:51:25 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//TODO
//Temporary just to leave way top the builtins once thet come.
static int	is_builtin(void)
{
	return (0);
}

static void	run_builtin(void)
{
	return ;
}

/*
**	The execution takes the commands given and executes them.
**	Built-ins modify the shell status when called alone, no fork happens.
**	Otherwise a pipeline is created.
*/
void	start_execution(t_list *cmd_lst)
{
	const size_t	cmd_num = ft_lstsize(cmd_lst);

	//TODO cool idea, but what if it fails? Malloc error or something
	//Actually, it'd just mess with execve behaviour no?
	//ft_lstiter(cmd_lst, build_path);
	//ft_lstiter(cmd_lst, build_argv);
	if (cmd_num == 1 && is_builtin())
		run_builtin();
	else
	{
		exec_cmd_pipe(cmd_lst, cmd_num);
		wait_children(cmd_num);
	}
}
