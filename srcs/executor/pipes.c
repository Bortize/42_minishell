/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:43:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 22:47:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

static void	close_pipe(int p[2])
{
	close(p[0]);
	close(p[1]);
}

void	clean_pipes(int pipev[CHILD_MAX - 1][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
		close_pipe(pipev[i++]);
}

int	configure_pipeline(int cmd_index, int cmd_count, int (*pipev)[2])
{
	if (cmd_count > 1)
	{
		if (cmd_index != cmd_count - 1)
			if (dup2(pipev[cmd_index][WRITE_END], STDOUT_FILENO) == -1)
				return (-1);
		if (cmd_index != 0)
			if (dup2(pipev[cmd_index - 1][READ_END], STDIN_FILENO) == -1)
				return (-1);
	}
	clean_pipes(pipev, cmd_count - 1);
	return (0);
}

int	create_pipes(int pipev[CHILD_MAX - 1][2], size_t cmd_count)
{
	size_t	i;

	i = 0;
	while (i < cmd_count - 1)
	{
		if (pipe(pipev[i]) == -1)
		{
			perror("PIPE:");
			while (i-- > 0)
				close_pipe(pipev[i]);
			return(-1);
		}
		i++;
	}
	return (0);
}
