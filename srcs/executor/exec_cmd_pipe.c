/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/21 14:56:25 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h> //TODO just placeholder printf

int	exec_cmd_pipe(t_list *cmd_lst, size_t cmdn)
{
	int		(*pipev)[2];
	pid_t	*pidv;
	size_t	i;
	char	**aux; //Doesn't belong here. Also, it leaks badly.
	int	dbg_i; //TODO DEL

	//--Setup TODO FTCALLOC
	pipev = calloc(sizeof(int *), cmdn - 1);
	pidv = calloc(sizeof(pid_t), cmdn);
	if (!pidv || !pipev)
	{
		free(pidv);
		free(pipev);
		return (-1); //TODO propagate error no_mem
	}
	/* TODO
	i = 0; //Create n pipes
	while (i < cmdn - 1)
	{
		if (pipe(pipev[i]) == -1)
		{
			//clean up
			//close_pipes(pipev, i);
			//free_mem(pidv pipev)
			return (-1); //TODO propagate error
		}
		i++;
	}
	*/
	i = 0; //Create n children
	while (i < cmdn)
	{
		t_cmd *cmd = cmd_lst->content;
		aux = build_str_arr(cmd->arg);
		dbg_i = 0;
		while (aux[dbg_i])
		{
			printf("Arg %i: %s\n", dbg_i, aux[i]);
			dbg_i++;
		}
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
			//TODO redirections plx
			//TODO execve
			printf("Child n:%zu Arg0 %s\n", i, aux[0]);
			execve(aux[0], aux, NULL);
			//TODO Something went wrong here
			//Do whatever bash does here
			perror("Execve>");
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
		//TODO I'm certain we need to do extra work here, let's just gather them
		//children process corpses.
		//close(pipev[i][0]);
		//close(pipev[i][1]);
		waitpid(pidv[i], NULL, 0);
		i++;
	}
	free(pipev);
	free(pidv);
	return (0);
}
