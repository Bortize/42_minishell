/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/21 11:56:09 by bgomez-r         ###   ########.fr       */
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
		cmd_lst = NULL;
		string_validator(line);
		split_in_cmds(line, &cmd_lst);
		system("leaks -q minishell");
		ft_lstiter(cmd_lst, print_cmd);
		ft_lstclear(&cmd_lst, &free_cmd);
		free(line);
	}
	return (0);
}
