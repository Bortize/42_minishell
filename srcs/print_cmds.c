/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 03:05:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/29 03:43:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

//This is meant to be be a logging/debug function.
//TODO Probably better and simpler with lst_map_i.

void	print_cmds(t_list *cmd_lst)
{
	while (cmd_lst)
	{
		printf("Command: %s\nArgument: %s\n", ((t_cmd *)cmd_lst->content)->cmd,
			((t_cmd *)cmd_lst->content)->arg);
		cmd_lst = cmd_lst->next;
	}
}
