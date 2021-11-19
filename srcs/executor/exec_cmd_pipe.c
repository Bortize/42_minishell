/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 20:05:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

//TODO Of course this is just a patch until our environment is done
#define PATH_STR "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
char	*get_path(char *file, char *path_env);

static void	close_pipe(int p[2])
{
	close(p[0]);
	close(p[1]);
}

static void	clean_pipes(int pipev[CHILD_MAX - 1][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
		close_pipe(pipev[i++]);
}

static int	configure_pipeline(int cmd_index, int cmd_count, int (*pipev)[2])
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

static int	create_pipes(int pipev[CHILD_MAX - 1][2], size_t cmd_count)
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

void	exec_child(t_cmd *cmd, size_t cmdn, int (*pipev)[2], size_t cmd_index)
{
	if (configure_pipeline(cmd_index, cmdn, pipev) == -1
	//TODO Inputs include here-doc and shouldn't
			|| redirect_input(cmd->lst_redir_in) == -1
			|| redirect_output(cmd->lst_redir_out) == -1)
		exit(errno);
	//TODO getpath considerations.
	execve(get_path(cmd->argv[0], PATH_STR), cmd->argv, NULL);
	//TODO Something went wrong here. Do whatever bash does here
	perror(cmd->argv[0]);
	exit(errno);
}

static int	fork_fail(void)
{
	//TODO
	//Error routine again
	//Sigkill all children, kill them all.
	perror("FORK");
	return (-1);
}

//TODO Only iterate using [i], and go through the cmd_list as if cmd_lst[i]
//It's probably less time efficient but cleaner and less redundant.
int	exec_cmd_pipe(t_list *cmd_lst, size_t cmdn)
{
	int		pipev[CHILD_MAX - 1][2];
	size_t	i;
	t_cmd	*cmd;

	if (create_pipes(pipev, cmdn) == -1)
		return (-1); //Memory error somewhere, someone'll handle that.
	i = 0;
	while (i < cmdn)
	{
		cmd = cmd_lst->content;
		g_pidv[i] = fork();
		if (g_pidv[i] == -1)
		{
			clean_pipes(pipev, i);
			return (fork_fail());
		}
		else if (g_pidv[i] == 0)
			exec_child(cmd, cmdn, pipev, i);
		cmd_lst = cmd_lst->next;
		i++;
	}
	clean_pipes(pipev, cmdn - 1);
	return (0);
}
