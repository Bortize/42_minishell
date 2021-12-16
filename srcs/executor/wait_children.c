/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 17:17:54 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	wait_children(size_t cmd_num, pid_t last_pid)
{
	int	status;

	cmd_num--;
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status) % 256;
	else if (WIFSIGNALED(status))
		g_status = 128 + WTERMSIG(status);
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
	}
}
