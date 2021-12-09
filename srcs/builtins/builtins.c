/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/08 22:39:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Parses the first token stored in the "args" array of the t_cmd structure to
** forward each builtins to its respective builtin function.
*/

void	builtins(/*t_list *cmd_lst, */t_list **env_lst, char **str_args)
{
	g_builtin = 1;
	if(ft_strcmp(str_args[0], "exit") == 0)
		builtins_exit(str_args);
	else if (ft_strcmp(str_args[0], "env") == 0)
		builtins_env(*env_lst);
	else if (ft_strcmp(str_args[0], "pwd") == 0)
		builtint_pwd(str_args[0]);
	else if (ft_strcmp(str_args[0], "echo") == 0)// << ===== cambiarlo porque puede llevar argumentos
	{
		printf("\n---- debugger 4 ---- \n\n");
//		ft_lstiter(cmd_lst, print_echo);
		print_echo_str(str_args);
	}
	else if (ft_strcmp(str_args[0], "cd") == 0)
	{
		printf("\n---- debugger 5 ---- \n\n");
		builtins_cd(str_args, *env_lst); //TODO I think this is needed.
	}
	else if (ft_strcmp(str_args[0], "export") == 0)
	{
		printf("\n---- debugger 6 ---- \n\n");
		//builtins_cd(str_args, env_lst);
	}
	else if (ft_strcmp(str_args[0], "unset") == 0)
		builtins_unset(env_lst, str_args);
	else
		g_builtin = 0;
}
