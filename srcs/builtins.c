/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/15 09:19:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_list *cmd_lst, t_list *env_lst, char *token)
{
	if (ft_strcmp(token, "env") == 0)
	{
		ft_lstiter(env_lst, print_env);
	}
	else if (ft_strcmp(token, "pwd") == 0)
	{
		builtint_pwd(token);
	}
	else if (ft_strcmp(token, "echo"))
	{
		printf("⚽ builtin\n");
		ft_lstiter(cmd_lst, print_echo);
	}
/*
	else if argumento == "pwd"
		ToDo
	else if artmento == "echo"
		ToDo
*/
}
