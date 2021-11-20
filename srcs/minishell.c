/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/20 12:57:38 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	*trimmed;
	t_list	*cmd_lst;
	t_list	*env_lst;

	(void)(argc);
	(void)(argv);
	env_lst = builtins_env(env);
	while (1)
	{
		line = NULL;
		line = readline("minishell> ");
		if (!line)
			break ;
		add_history(line);
		trimmed = ft_strtrim(line, " ");
		free(line);
		if (trimmed && *trimmed && string_validator(trimmed))
		{
			cmd_lst = NULL;
			split_in_cmds(trimmed, &cmd_lst, env_lst);
			//TODO build string array before executor (parser?), also check errors
			t_cmd	*cmd;
			cmd = (t_cmd *)(cmd_lst->content);
			cmd->argv = build_str_arr(cmd->arg);
			//--This before executor [END]
			ft_lstiter(cmd_lst, print_cmd);
			builtins(cmd_lst, env_lst, cmd->argv);// << =============== WORKING HERE NOW
			//exec_cmd_pipe(cmd_lst, ft_lstsize(cmd_lst));
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		free(trimmed);
		system("leaks -q minishell");
	}
	ft_lstclear(&env_lst, free_env_var);
//	system("leaks -q minishell");
	return (0);
}
