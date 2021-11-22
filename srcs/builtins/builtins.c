/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/20 16:56:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_list *cmd_lst, t_list *env_lst, char **str_args)
{
	if(ft_strcmp(str_args[0], "exit") == 0)// <<====== cambiarlo porque puede llevar argumentos
	{
		printf("\n---- debbuger 1 ---- \n\n");
//		printf("%s\n", (char *)cmd->arg);
//		ft_lstiter(cmd_lst, ft_exit);
//		ft_exit(cmd_lst);
	}
	else if (ft_strcmp(str_args[0], "env") == 0)
	{
		printf("\n---- debbuger 2 ---- \n\n");
		ft_lstiter(env_lst, print_env);
	}
	else if (ft_strcmp(str_args[0], "pwd") == 0)
	{
		printf("\n---- debbuger 3 ---- \n\n");
		builtint_pwd(str_args[0]);
	}
	else if (ft_strcmp(str_args[0], "echo") == 0)// << ===== cambiarlo porque puede llevar argumentos
	{
		printf("\n---- debbuger 4 ---- \n\n");
//		ft_lstiter(cmd_lst, print_echo);
		print_echo_str(str_args);
	}
	else if (ft_strcmp(str_args[0], "cd") == 0)
	{
		printf("\n---- debbuger 5 ---- \n\n");
		ft_lstiter(cmd_lst, print_echo);
		builtins_cd(str_args, env_lst);
	}

}
