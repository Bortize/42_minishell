/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/22 23:01:10 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

#include <stdio.h> //TODO just placeholder printf
/*
static int	open_files(t_list *redir_lst)
{
	int	fd;

	fd = 0;
	while (redir_lst && fd != -1)
	{
		fd = open();
		redir_lst = redir_lst->next;
	}
	return (fd);
}
*/

int	exec_cmd_pipe(t_list *cmd_lst, size_t cmdn)
{
	int		(*pipev)[2];
	pid_t	*pidv;
	size_t	i;

	//--Setup TODO FTCALLOC
	pipev = calloc(sizeof(int *), cmdn - 1);
	pidv = calloc(sizeof(pid_t), cmdn);
	if (!pidv || !pipev)
	{
		free(pidv);
		free(pipev);
		return (-1); //TODO propagate error no_mem
	}
	i = 0; //Create n pipes
	while (i < cmdn - 1)
	{
		if (pipe(pipev[i]) == -1)
		{
			//clean up TODO
			//close_pipes(pipev, i);
			//free_mem(pidv pipev)
			return (-1); //TODO propagate error
		}
		i++;
	}
	i = 0; //Create n children
	while (i < cmdn)
	{
		t_cmd *cmd = cmd_lst->content;
		cmd->argv = build_str_arr(cmd->arg); //TODO do this before executor, also check errors
		pidv[i] = fork();
		if (pidv[i] == -1)
		{
			//TODO
			//Error routine again
			//Sigkill all children, kill them all.
			return (-1);
		}
		else if (pidv[i] == 0)
		{
			//This is child
			//Plumbing
			if (cmdn > 1)
			{
				if (i != cmdn - 1)
					dup2(pipev[i][WRITE_END], 1);
				if (i != 0)
					dup2(pipev[i - 1][READ_END], 0);
			}
			//TODO redirections plx
			execve(cmd->argv[0], cmd->argv, NULL);
			//TODO Something went wrong here
			//Do whatever bash does here
			perror(cmd->argv[0]);
			exit(-1);
		}
		else
		{
			cmd_lst = cmd_lst->next;
			i++;
		}
	}
	//Wait all
	i = 0;
	while (i < cmdn)
	{
		//TODO Do we need to do extra work here?
		//TODO How do we get the exit status of the last pid
		if (i != cmdn - 1) //Close pipes, otherwise any read'll hang
			//Closing the pipe will 'send' EOF to any reader.
		{
			close(pipev[i][0]);
			close(pipev[i][1]);
		}
		waitpid(pidv[i], NULL, 0);
		i++;
	}
	free(pipev);
	free(pidv);
	return (0);
}
