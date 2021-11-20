/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 22:45:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

//TODO Of course this is just a patch until our environment is done
#define PATH_STR "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"

void	exec_child(t_cmd *cmd, size_t cmdn, int (*pipev)[2], size_t cmd_index)
{
	if (configure_pipeline(cmd_index, cmdn, pipev) == -1
			|| redirect_input(cmd->lst_redir_in) == -1
			|| redirect_output(cmd->lst_redir_out) == -1)
		exit(errno);
	execve(get_path(cmd->argv[0], PATH_STR), cmd->argv, NULL);
	perror(cmd->argv[0]);
	exit(errno);
}

static int	fork_fail(int pipev[CHILD_MAX - 1][2], size_t fail_at)
{
	perror("FORK");
	clean_pipes(pipev, fail_at);
	//TODO Sigkill all children, kill them all.
	return (-1);
}

/*
**	Execute the commands given in a pipeline.
**	Be as clean as possible with memory usage.
**	Don't handle children unless failure.
**	Return -1 on error, 0 otherwise.
*/
int	exec_cmd_pipe(t_list *cmd_lst, size_t cmdn)
{
	int		pipev[CHILD_MAX - 1][2];
	size_t	i;

	if (create_pipes(pipev, cmdn) == -1)
		//Memory error somewhere, someone'll handle that.
		return (-1);
	i = 0;
	while (i < cmdn)
	{
		g_pidv[i] = fork();
		if (g_pidv[i] == -1)
		//Memory error somewhere, someone'll handle that.
			return (fork_fail(pipev, i));
		else if (g_pidv[i] == 0)
			exec_child(ft_lst_at(cmd_lst, i)->content, cmdn, pipev, i);
		i++;
	}
	clean_pipes(pipev, cmdn - 1);
	return (0);
}
