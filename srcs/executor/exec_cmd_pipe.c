/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/24 23:02:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> //perror

#define READ_END 0
#define WRITE_END 1

static int	redirect_input(t_list *in_lst)
{
	int			fd;
	char		*file_path;
	t_redirect	*redir_data;

	fd = STDIN_FILENO;
	while (in_lst)
	{
		close(fd);
//TODO we need get_path to use relative addresses.
	//file_path = get_path(in_lst->content);
		redir_data = in_lst->content;
		file_path = redir_data->text;
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
			break ;
		fd = dup2(fd, STDIN_FILENO);
		if (fd == -1)
			break ;
	//free(file_path);
		in_lst = in_lst->next;
	}
	if (fd == -1)
		perror(redir_data->text);
	return (fd);
}

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
		//TODO build string array before executor (parser?), also check errors
		cmd->argv = build_str_arr(cmd->arg);
		if (!cmd->arg)
			return (-1);//No memory
		//--This before executor [END]
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
			//Plumbing
			//TODO configure_pipes(); to hold this part of code
			if (cmdn > 1)
			{
				if (i != cmdn - 1)
					dup2(pipev[i][WRITE_END], 1);
				if (i != 0)
					dup2(pipev[i - 1][READ_END], 0);
			}
			clean_pipes(pipev, i, cmdn - 1);
			//TODO Inputs include here-doc and shouldn't
			if (redirect_input(cmd->lst_redir_in) == -1)
				exit(-1); //TODO couldn't open file error
			//TODO output redirections
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
