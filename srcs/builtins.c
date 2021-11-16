/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/16 15:36:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_list *cmd_lst, t_list *env_lst)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)(cmd_lst->content);
	if(ft_strcmp(cmd->arg, "exit") == 0)// <<====== cambiarlo porque puede llevar argumentos
	{
		printf("\n---- debbuger 1 ---- \n\n");
		printf("%s\n", cmd->arg);
//		ft_lstiter(cmd_lst, ft_exit);
//		ft_exit(cmd_lst);
	}
	else if (ft_strcmp(cmd->arg, "env") == 0)
	{
		printf("\n---- debbuger 2 ---- \n\n");
		ft_lstiter(env_lst, print_env);
	}
	else if (ft_strcmp(cmd->arg, "pwd") == 0)
	{
		printf("\n---- debbuger 3 ---- \n\n");
		builtint_pwd(cmd->arg);
	}
	else if (ft_strcmp(cmd->arg, "echo") == 0)// << ===== cambiarlo porque puede llevar argumentos
	{
		printf("\n---- debbuger 4 ---- \n\n");
		ft_lstiter(cmd_lst, print_echo);
	}
	else
	{
		printf("");
	}
}
