/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/15 13:26:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdlib.h>

#include <sys/ioctl.h>
#include <termios.h>

#include <unistd.h>

int	main(void)
{
	char	*line;
	char	*trimmed;
	t_list	*cmd_lst;
	struct termios	tty_attr;

	ioctl(STDIN_FILENO, TIOCGETA, &tty_attr);
	tty_attr.c_lflag &= ~ECHOCTL;
	ioctl(STDIN_FILENO, TIOCSETA, &tty_attr);
	set_msh_signals();
	system("stty -a");
	//system("stty -echoctl");
	//system("stty -a");
	g_interrupted = 0;
	printf("RL version: %s\n", rl_library_version);
	printf("RL version: %#X\n", rl_readline_version);
	printf("RL redisplay hook: %p\n", rl_redisplay_function);
	while (1)
	{
		line = NULL;
		line = readline("minishell> ");
		rl_already_prompted = 0;
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
