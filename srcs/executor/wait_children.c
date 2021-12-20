/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/20 17:39:40 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <signal.h>

void	wait_children(size_t cmd_num, pid_t last_pid)
{
	int	status;

	cmd_num--;
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		set_exit_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 1);
		set_exit_status(128 + WTERMSIG(status));
	}
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
	}
	g_status &= ~STS_HAS_CHILD;
}
