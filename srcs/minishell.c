/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/19 19:52:00 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/ioctl.h>
#include <termios.h>

static void	initialize_minishell(void)
{
	struct termios	tty_attr;

	ioctl(STDIN_FILENO, TIOCGETA, &tty_attr);
	tty_attr.c_lflag &= ~ECHOCTL;
	ioctl(STDIN_FILENO, TIOCSETA, &tty_attr);
	set_msh_signals();
	g_status = 0;
}

static int	only_spaces(char *str)
{
	if (!str)
		return (1);
	while (*str && ft_isspace(*str))
		str++;
	return (*str == '\0');
}

/*
** Prints the prompt and receives in a pointer *line
** the line typed by the user
*/

static char	*wait_input(void)
{
	char	*line;

	g_status &= ~STS_INTERRUPT;
	line = readline("minishell> ");
	if (!line)
		return (line);
	while (g_status & STS_INTERRUPT || only_spaces(line))
	{
		if (g_status & STS_INTERRUPT)
			g_status &= ~STS_INTERRUPT;
		free(line);
		line = readline("minishell> ");
		if (!line)
			return (line);
	}
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*cmd_lst;
	t_list	*env_lst;

	(void)(argv);
	(void)(argc);
	initialize_minishell();
	env_lst = build_env_lst(envp);
	update_shlvl(env_lst);
	line = wait_input();
	while (line)
	{
		add_history(line);
		if (parse_line(line, &cmd_lst, env_lst) == 0)
		{
			start_execution(cmd_lst, &env_lst);
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		free(line);
		line = wait_input();
	}
	ft_lstclear(&env_lst, free_env_var);
	ft_putstr_fd("exit\n", 1);
	return (0);
}
