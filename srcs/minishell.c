/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/15 14:17:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>

#include <sys/ioctl.h>
#include <termios.h>

#include <unistd.h>

static void	initialize_minishell(void)
{
	struct termios	tty_attr;

	ioctl(STDIN_FILENO, TIOCGETA, &tty_attr);
	tty_attr.c_lflag &= ~ECHOCTL;
	ioctl(STDIN_FILENO, TIOCSETA, &tty_attr);
	set_msh_signals();
	g_interrupted = 0;
}

static char	*wait_input(void)
{
	char	*line;

	g_interrupted = 0;
	line = readline("minishell> ");
	while (g_interrupted)
	{
		g_interrupted = 0;
		free(line);
		line = readline("minishell> ");
	}
	return (line);
}

int	main(void)
{
	char	*line;
	char	*trimmed;
	t_list	*cmd_lst;

	initialize_minishell();
	while (1)
	{
		line = wait_input();
		if (!line)
			break ;
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
