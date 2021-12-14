/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/14 23:02:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	wait_children(size_t cmd_num)
{
	int	status;

	cmd_num--;
	waitpid(g_pidv[cmd_num], &status, 0);
	g_pidv[cmd_num] = 0;
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status) % 256;
	else if (WIFSIGNALED(status))
		g_status = 128 + WTERMSIG(status);
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
		g_pidv[cmd_num] = 0;
	}
}
