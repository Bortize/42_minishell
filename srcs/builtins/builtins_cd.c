/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/08 15:23:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

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
** Search 'env_lst' for the key to update its value with the path
** passed as parameter.
*/

char	*set_key_value(t_list *env_lst, char *str, char *search)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = search;
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(env_lst, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (((t_env_var *)found_shlvl->content)->value);
}

/*
** Moves the prompt between directory levels
*/

int	builtins_cd(char **arg, t_list *env_lst)
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
			return (-1);
		}
	}

	pwd = getcwd(NULL, 4096);
	if (i == 1)
	{
		set_key_value(env_lst, pwd, "OLDPWD");// Guarda el path antes de cambiar
		chdir(get_current_path(env_lst, "HOME"));// busca el value de HOME y se cambia
		set_key_value(env_lst, get_current_path(env_lst, "HOME"), "PWD");// Establece PWD al nuevo valor
	}
	else if (ft_strcmp(arg[0], "cd") == 0 && ft_strcmp(arg[1], "--") == 0)
	{
		set_key_value(env_lst, pwd, "OLDPWD");// Guarda el path antes de cambiar
		chdir(get_current_path(env_lst, "HOME"));// busca el value de HOME y se cambia
		set_key_value(env_lst, get_current_path(env_lst, "HOME"), "PWD");
	}
	else if (ft_strcmp(arg[1], "..") == 0)
	{
		set_key_value(env_lst, pwd, "OLDPWD");
		chdir("..");
		free(pwd);
		pwd = getcwd(NULL, 4096);
		set_key_value(env_lst, pwd, "PWD");
	}
	else if (ft_strcmp(arg[1], "-") == 0)
	{
		aux = ft_strdup(get_current_path(env_lst, "OLDPWD"));
		set_key_value(env_lst, pwd, "OLDPWD");
		chdir(aux);
		set_key_value(env_lst, aux, "PWD");
		free(aux);
	}
	else
	{
		if (chdir(arg[1]) == -1)
			perror("cd");
	}
	free(pwd);
	return (0);
}
