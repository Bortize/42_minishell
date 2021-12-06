/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/06 19:09:29 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

char *get_oldpwd(t_list *env_lst, char *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;
	char *gor;

	gor = str;

	shelevelref.key = "OLDPWD";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	printf("%p\n", found_shlvl);
	tmp = found_shlvl->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (((t_env_var *)found_shlvl->content)->value);
}

char	*get_home(t_list *env_lst)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "HOME";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	return (tmp->value);
}

void builtins_cd(char **arg, t_list *env_lst)
{
	(void) (arg);
	(void) (env_lst);


	char *pwd;
	int i;

	i = 0;
	while(arg[i])
	{
		i++;
		if (i == 3)
		{
			printf("to many arguments \n");
			return ;
		}
	}

	pwd = getcwd(NULL, 4096);
	if (ft_strcmp(arg[1], "--") == 0)
	{
		chdir(get_home(env_lst));
		free(pwd);
		return ;
	}
	else if (ft_strcmp(arg[1], "..") == 0)
	{
		printf("The old value is %s\n", get_oldpwd(env_lst, pwd));
		chdir("..");
	}
	else
	{
		printf("La luz %s\n", arg[1]);
		chdir(arg[1]);
	}
	free(pwd);
/*
	else if (ft_strcmp(arg, "-"))
	{
		chdir( Devolver al prompt anterior  );
	}
	else if (arg[2])
	{
		chdir(: Devolver ERROR );
	}
	else
	{
		chdir(arg);
	}
*/
}
