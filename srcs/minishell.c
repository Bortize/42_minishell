/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/09 13:10:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#include <sys/ioctl.h>
#include <termios.h>

static int	build_argvs(t_list *cmd_lst)
{
	t_cmd	*cmd;

	while (cmd_lst)
	{
		cmd = (t_cmd *)cmd_lst->content;
		if (!cmd->arg)
			return (0);
		cmd->argv = build_str_arr(cmd->arg);
		if (!cmd->argv)
			return (1);//TODO No memory error
		cmd_lst = cmd_lst->next;
	}
	return (0);
}

static int	parse_line(char *line, t_list **cmd_lst, t_list *env_lst)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " ");
	if (trimmed && *trimmed && string_validator(trimmed))
	{
		*cmd_lst = NULL;
		split_in_cmds(trimmed, cmd_lst, env_lst);
	}
	free(trimmed);
	if (build_argvs(*cmd_lst) == -1)
		return (-1);
	//ft_lstiter(*cmd_lst, print_cmd);
	return (0);
}

static void	initialize_minishell(void)
{
	struct termios	tty_attr;

	ioctl(STDIN_FILENO, TIOCGETA, &tty_attr);
	tty_attr.c_lflag &= ~ECHOCTL;
	ioctl(STDIN_FILENO, TIOCSETA, &tty_attr);
	set_msh_signals();
	g_interrupted = 0;
	g_child = 0;
}

static int	only_spaces(char *str)
{
	if (!str)
		return (1);
	while (*str && *str == ' ')//ft_isspace(*str))
		str++;
	return (*str == '\0');
}

static char	*wait_input(void)
{
	char	*line;

	g_interrupted = 0;
	line = readline("minishell> ");
	if (!line)
		return (line);
	while (g_interrupted || only_spaces(line))
	{
		if (g_interrupted)
		g_interrupted = 0;
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
	(void)(argc); //TODO Just return and print error og argc > 1;
	initialize_minishell();
	env_lst = build_env_lst(envp);
	update_shlvl(env_lst);
	ft_lstiter(env_lst, print_env);
	while (1)
	{
		line = wait_input();
		if (!line)
			break ;
		add_history(line);
		if (parse_line(line, &cmd_lst, NULL) == -1)
			return (-1); //TODO Another error, should behave better than this
		free(line);
		start_execution(cmd_lst, &env_lst);
		ft_lstclear(&cmd_lst, &free_cmd);
		system("leaks -q minishell");
	}
	ft_lstclear(&env_lst, free_env_var);
//	system("leaks -q minishell");
	return (0);
}
