/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/24 14:02:13 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdlib.h>

int	main(void)
{
	char	*line;
	t_list	*cmd_lst;

	while (1)
	{
		line = readline("minishell> ");
		add_history(line);
		if (string_validator(line))
		{
			cmd_lst = NULL;
			split_in_cmds(line, &cmd_lst);
			ft_lstiter(cmd_lst, print_cmd);
			ft_lstclear(&cmd_lst, &free_cmd);
		}
		system("leaks -q minishell");
		free(line);
	}
	return (0);
}
