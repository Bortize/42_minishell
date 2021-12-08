/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/08 16:51:14 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

/*
** Searches the linked list of environment variables for the key HOME to
** obtain its value and return it as a return.
** @ content_env -> Node contents of the environment variable list
** @ lst_env -> environment variable list
** @ tmp ->
*/

char	*get_current_path(t_list *env_lst, char *str)
{
	t_env_var content_env;
	t_list	*lst_env;
	t_env_var *tmp;

	content_env.key = str;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	tmp = lst_env->content;
	return (tmp->value);
}

/*
** Search 'env_lst' for the key to update its value with the path
** that the function receives as parameter.
*/

char	*set_key_value(t_list *env_lst, char *str, char *search)
{
	t_env_var content_env;
	t_list	*lst_env;
	t_env_var *tmp;

	content_env.key = search;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	tmp = lst_env->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (tmp->value);
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
