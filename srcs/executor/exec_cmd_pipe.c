/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/20 17:27:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

static void	exec_child(t_cmd *cmd, t_list *env_lst)
{
	char			**envp;
	char			*file_path;
	t_builtin_funcp	builtin;

	if (redirect_input(cmd->lst_redir_in, cmd->heredoc_filename) == -1
		|| redirect_output(cmd->lst_redir_out) == -1)
		exit(1);
	builtin = NULL;
	if (cmd->argv == NULL || cmd->argv[0] == NULL)
		exit(0);
	builtin = get_builtin(cmd->argv[0]);
	if (builtin)
		exit(builtin(cmd->argv, &env_lst));
	file_path = get_path(cmd->argv[0], get_current_path(env_lst, "PATH"));
	if (!file_path)
	{
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	envp = stringify_env(env_lst);
	if (envp)
		execve(file_path, cmd->argv, envp);
	perror_and_exit(cmd->argv[0], errno);
}

static void	fatal_fork_fail(int pipev[CHILD_MAX - 1][2], size_t fail_at)
{
	int	error;

	error = errno;
	perror("FORK");
	clean_pipes(pipev, fail_at);
	while (fail_at > 0)
	{
		wait(NULL);
		fail_at--;
	}
	exit(error);
}

/*
**	Execute the commands given in a pipeline.
**	Be as clean as possible with memory usage.
**	Don't handle children unless failure.
**	Return -1 on error, 0 otherwise.
*/

void	exec_cmd_pipe(t_list *cmd_lst, t_list *env_lst, size_t cmdn,
			pid_t *lst_pid)
{
	int		pipev[CHILD_MAX - 1][2];
	size_t	i;

	if (create_pipes(pipev, cmdn) == -1)
		perror_and_exit("FATAL:", errno);
	i = 0;
	while (i < cmdn)
	{
		*lst_pid = fork();
		if (*lst_pid == -1)
			fatal_fork_fail(pipev, i);
		else if (*lst_pid == 0)
		{
			g_status |= STS_IS_CHILD;
			if (configure_pipeline(i, cmdn, pipev) == -1)
				exit(errno);
			exec_child(ft_lst_at(cmd_lst, i)->content, env_lst);
		}
		else
			g_status |= STS_HAS_CHILD;
		i++;
	}
	clean_pipes(pipev, cmdn - 1);
}
