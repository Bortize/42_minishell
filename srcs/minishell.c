/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/10 16:01:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdlib.h>

#include <stdio.h>

int	main(void)
{
	char	*line;
	char	*trimmed;
	t_list	*cmd_lst;

	set_msh_signals();
	while (1)
	{
		line = NULL;
		line = readline("minishell> ");
		printf("%p\n", line);
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
			//exec_cmd((t_cmd *)cmd_lst->content);
			//exec_cmd_pipe(cmd_lst, ft_lstsize(cmd_lst));
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		free(trimmed);
		system("leaks -q minishell");
	}
	return (0);
}
