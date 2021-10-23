/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/23 06:44:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

#include <stdio.h> //TODO just placeholder printf
/*
static int	get_oflag()
{//HOW TO HANDLE HERE-DOC? Write on a tmpfile, somehow have a program cat-int out into stdin that ofc, got redirected?
	if (redir_out)
		O_WRONLY | O_CREAT | O_TRUNC;
	else if (redir_out_append)
		O_WRONLY | O_CREAT | O_APPEND;
	else if (redir_in)
		O_RDONLY;
}

static int	open_files(t_list *redir_lst)
{
	int	fd;
	int	o_flag;

	o_flag =
	fd = open();
	redir_lst = redir_lst->next;
	while (redir_lst && fd != -1)
	{
		close(fd);
		fd = open();
		redir_lst = redir_lst->next;
	}
	return (fd);
}*/

void	clean_pipes(int (*pipev)[2], int pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != pos)
			close(pipev[i][WRITE_END]);
		else if (i != pos - 1)
			close(pipev[i][READ_END]);
		i++;
	}
}

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
			clean_pipes(pipev, i, cmdn);
			//TODO redirections plx
			/*
			if (cmd_lst->lst_redir_out)
			{
				close(0);
				redir_fd = open_files();
				if (redir_fd == -1)
					exit(-1); //TODO error some file couldn't be opened
				dup2(redir_fd, 0);
			}
			*/
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
	clean_pipes(pipev, -1, cmdn);
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
