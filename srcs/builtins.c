/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/13 13:34:44 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_list *env_lst, char *token)
{
	if (ft_strncmp(token, "env", 3) == 0)
	{
		ft_lstiter(env_lst, print_env);
	}
	else if (ft_strncmp(token, "pwd", 3) == 0)
	{
		builtint_pwd(token);
//		ft_lstiter(env_lst, print_env);
	}
/*
	else if argumento == "pwd"
		ToDo
	else if artmento == "echo"
		ToDo
*/
}