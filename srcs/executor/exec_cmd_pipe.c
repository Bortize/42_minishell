/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/09 12:33:24 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

//TODO Of course this is just a patch until our environment is done
#define PATH_STR "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"

static void	exec_child(t_cmd *cmd, t_list *env_lst)
{
	char	**envp;

	if (redirect_input(cmd->lst_redir_in) == -1
			|| redirect_output(cmd->lst_redir_out) == -1)
		exit(errno);
	g_builtin = 0;
	//builtins(cmd->argv, env_lst);//FIXME that should work like that, aprox
	if (g_builtin == 0)
	{
		envp = build_str_arr(env_lst); //TODO needs to stringify key-value
		execve(get_path(cmd->argv[0], PATH_STR), cmd->argv, envp);
	}
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
int	exec_cmd_pipe(t_list *cmd_lst, t_list *env_lst, size_t cmdn)
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
		{
			if (configure_pipeline(i, cmdn, pipev) == -1)
				exit(errno);
			//exit(42);
			exec_child(ft_lst_at(cmd_lst, i)->content, env_lst);
		}
		i++;
	}
	clean_pipes(pipev, cmdn - 1);
	return (0);
}
