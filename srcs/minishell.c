/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/25 12:40:58 by bgomez-r         ###   ########.fr       */
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

	while (1)
	{
		line = NULL;
		line = readline("minishell> ");
		add_history(line);
		trimmed = ft_strtrim(line, " ");
		printf("trimmed %s\n", trimmed);
		free(line);
		if (trimmed && *trimmed && string_validator(trimmed))
		{
			cmd_lst = NULL;
			split_in_cmds(trimmed, &cmd_lst);
			ft_lstiter(cmd_lst, print_cmd);
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		free(trimmed);
		system("leaks -q minishell");
	}
	return (0);
}
