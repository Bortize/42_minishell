/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/07 18:05:39 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

char *set_pwd(t_list *env_lst, char *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "PWD";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (((t_env_var *)found_shlvl->content)->value);
}

char *get_oldpwd(t_list *env_lst)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "OLDPWD";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	return (((t_env_var *)found_shlvl->content)->value);
}

char	*get_pwd(t_list *env_lst)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "PWD";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	printf("---get_pwd--- %s=%s\n", tmp->key, tmp->value );
	return (((t_env_var *)found_shlvl->content)->value);
}

/*
** It searches in 'env_lst' the key OLDPWD to update its value with the
** path that is passed by parameter.
*/

char *set_oldpwd(t_list *env_lst, char *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "OLDPWD";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (((t_env_var *)found_shlvl->content)->value);
}

/*
** Searches the linked list of environment variables for the key HOME to
** obtain its value and return it as a return.
*/

char	*get_current_path(t_list *env_lst, char *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = str;
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	return (tmp->value);
}

/*
** Moves the prompt between directory levels
*/

void builtins_cd(char **arg, t_list *env_lst)
{
	(void) (arg);
	(void) (env_lst);


	char *pwd;
	char *aux;
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
	if (i == 1)
	{
		set_oldpwd(env_lst, pwd);
		chdir(get_current_path(env_lst, "HOME"));
//		free(pwd);
//		return ;
	}
	else if (ft_strcmp(arg[0], "cd") == 0 && ft_strcmp(arg[1], "--") == 0)
	{
		set_oldpwd(env_lst, pwd);
		chdir(get_current_path(env_lst, "HOME"));
//		free(pwd);
//		return ;
	}
/*	else if (ft_strcmp(arg[1], "..") == 0)
	{
		set_oldpwd(env_lst, pwd);
		chdir("..");
		free(pwd);
		pwd = getcwd(NULL, 4096);
		set_pwd(env_lst, pwd);
//		free(pwd);
//		return ;
	}*/
	else if (ft_strcmp(arg[1], "-") == 0)
	{
		aux = ft_strdup(get_pwd(env_lst));
		printf("💥%s\n", aux);
		chdir(get_oldpwd(env_lst));
//		set_oldpwd(env_lst, aux);
//		free(aux)*/
	}
	else
	{
		if (chdir(arg[1]) == -1)
			perror("cd");
	}
//	printf("💥💥💥💥%s\n", get_pwd(env_lst));
//	set_pwd(env_lst, get_pwd(env_lst));
	free(pwd);
	return ;
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
