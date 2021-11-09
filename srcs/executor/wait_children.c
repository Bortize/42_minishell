/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/09 20:14:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	wait_children(size_t cmd_num)
{
	int	status;

	cmd_num--;
	waitpid(g_pidv[cmd_num], &status, 0);
	if (WIFEXITED(status))
		printf("Last child exit status: %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("Last got signaled: %d\n", WTERMSIG(status));
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
	}
}
