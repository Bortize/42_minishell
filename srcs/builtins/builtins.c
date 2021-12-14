/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/14 22:20:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Parses the first token stored in the "args" array of the t_cmd structure to
** forward each builtins to its respective builtin function.
*/

int	builtins(t_list **env_lst, char **str_args)
{
	g_builtin = 0;
	if (str_args[0] == NULL)
		return (-1);
	g_builtin = 1;
	if (ft_strcmp(str_args[0], "exit") == 0)
		return (builtins_exit(str_args));
	if (ft_strcmp(str_args[0], "env") == 0)
		return (builtins_env(*env_lst));
	if (ft_strcmp(str_args[0], "pwd") == 0)
		return (builtint_pwd(str_args[0]));
	if (ft_strcmp(str_args[0], "echo") == 0)
		return (print_echo_str(str_args));
	if (ft_strcmp(str_args[0], "cd") == 0)
		return (builtins_cd(str_args, *env_lst));
	if (ft_strcmp(str_args[0], "export") == 0)
		return (builtins_export(env_lst, str_args));
	if (ft_strcmp(str_args[0], "unset") == 0)
		return (builtins_unset(env_lst, str_args));
	g_builtin = 0;
	return (-1);
}
