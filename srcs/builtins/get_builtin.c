/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:02:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/20 16:44:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	Return the function pointer to the builtin named in the string.
**	NULL if none.
*/

t_builtin_funcp	get_builtin(char *str)
{
	if (str == NULL)
		return (NULL);
	else if (ft_strcmp(str, "exit") == 0)
		return (builtins_exit);
	else if (ft_strcmp(str, "env") == 0)
		return (builtins_env);
	else if (ft_strcmp(str, "pwd") == 0)
		return (builtins_pwd);
	else if (ft_strcmp(str, "echo") == 0)
		return (builtins_echo);
	else if (ft_strcmp(str, "cd") == 0)
		return (builtins_cd);
	else if (ft_strcmp(str, "export") == 0)
		return (builtins_export);
	else if (ft_strcmp(str, "unset") == 0)
		return (builtins_unset);
	return (NULL);
}
