/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/14 18:54:16 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdlib.h>

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	main(void)
{
	char	*line;
	char	*trimmed;
	t_list	*cmd_lst;

	system("stty -a");
	set_msh_signals();
	g_interrupted = 0;
	printf("RL version: %s\n", rl_library_version);
	printf("RL version: %#X\n", rl_readline_version);
	printf("RL redisplay hook: %p\n", rl_redisplay_function);
	printf("RL redisplay hook: %p\n", rl_redisplay_function);
	while (1)
	{
		line = NULL;
		line = readline("minishell> ");
		if (g_interrupted)
		{
			free(line);
			g_interrupted = 0;
			continue ;
		}
		if (!line)
			printf("%p\n", line);
		if (line == NULL)
			break ;
		g_interrupted = 0;
		add_history(line);
		trimmed = ft_strtrim(line, " ");
		free(line);
		if (trimmed && *trimmed && string_validator(trimmed))
		{
			cmd_lst = NULL;
			split_in_cmds(trimmed, &cmd_lst);
			ft_lstiter(cmd_lst, print_cmd);
			start_execution(cmd_lst);
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		free(trimmed);
		system("leaks -q minishell");
	}
	return (0);
}
