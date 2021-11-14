/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:23:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/14 18:30:44 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_token(void *str)
{
	printf("%s ", str);
}

void	print_echo(void *elem)
{
	t_cmd *cmd;

	cmd = (t_cmd *)elem;
//	cmd->arg->next;
	printf("🏀echo \n");
	cmd->arg = cmd->arg->next;
	ft_lstiter(cmd->arg, print_token);
}
