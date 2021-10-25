/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/25 15:36:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

static void	clean_pipes(int (*pipev)[2], int pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != pos)
			close(pipev[i][WRITE_END]);
		if (i != pos - 1)
			close(pipev[i][READ_END]);
		i++;
	}
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
	clean_pipes(pipev, cmd_index, cmd_count - 1);
	return (0);
}

//TODO Have the child open it's pipe?
//Maybe open one pipe every loop sans the last one, and just close it?
//It should keep this function compact and the pipe-closing simpler
static int	alloc_memory(pid_t **pidv, int (**pipev)[2], size_t cmd_count)
{
	size_t	i;

	*pidv = ft_calloc(sizeof(pid_t), cmd_count);
	*pipev = ft_calloc(sizeof(int *), cmd_count - 1);
	if (!*pidv || !*pipev)
	{
		perror("MINSH:");
		free(*pidv);
		free(*pipev);
		return (-1); //TODO me error
	}
	i = 0;
	while (i < cmd_count - 1)
	{
		if (pipe((*pipev)[i]) == -1)
		{
			perror("PIPE:");
			while (i-- > 0)
			{
				close((*pipev)[i][WRITE_END]);
				close((*pipev)[i][READ_END]);
			}
			free(*pidv);
			free(*pipev);
			return(-1);
		}
		i++;
	}
	return (0);
}

void	exec_child(t_cmd *cmd, size_t cmdn, int (*pipev)[2], size_t cmd_index)
{
	if (configure_pipeline(cmd_index, cmdn, pipev) == -1)
		exit (-1); //TODO error with pipes
	//TODO Inputs include here-doc and shouldn't
	if (redirect_input(cmd->lst_redir_in) == -1)
		exit(-1); //TODO couldn't open file error
	//TODO output redirections
	execve(cmd->argv[0], cmd->argv, NULL);
	//TODO Something went wrong here. Do whatever bash does here
	perror(cmd->argv[0]);
	exit(-1);
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
	int		(*pipev)[2];
	pid_t	*pidv;
	size_t	i;

	if (alloc_memory(&pidv, &pipev, cmdn) == -1)
		return (-1); //Memory error somewhere, someone'll handle that.
	i = 0; //Create n children
	while (i < cmdn)
	{
		t_cmd *cmd = cmd_lst->content;
		//TODO build string array before executor (parser?), also check errors
		cmd->argv = build_str_arr(cmd->arg);
		if (!cmd->arg)
			return (-1);//No memory
		//--This before executor [END]
		pidv[i] = fork();
		if (pidv[i] == -1)
			return (fork_fail());
		else if (pidv[i] == 0)
			exec_child(cmd, cmdn, pipev, i);
		else
		{
			cmd_lst = cmd_lst->next;
			i++;
		}
	}
	//Wait all
	clean_pipes(pipev, -1, cmdn - 1);
		//TODO Do we need to do extra work here?
		//TODO How do we get the exit status of the last pid
	i = 0;
	while (i < cmdn)
	{
		waitpid(pidv[i], NULL, 0);
		i++;
	}
	free(pipev);
	free(pidv);
	return (0);
}
