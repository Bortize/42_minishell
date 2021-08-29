/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/08/29 03:24:56 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	t_list	*cmd_lst;

	while (1)
	{
		line = readline("minishell> ");
		add_history(line);
		cmd_lst = split_in_cmds(line);
		system("leaks -q minishell");
		print_cmds(cmd_lst);
		ft_lstclear(&cmd_lst, &free_cmd);
		free(line);
	}
	return (0);
}
