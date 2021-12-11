/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:35:32 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/11 22:10:14 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Searches the linked list of environment variables for the key HOME to
** obtain its value and return it as a return.
** @ content_env -> Node contents of the environment variable list
** @ lst_env -> environment variable list
** @ tmp -> content of the struct
*/

static char	*get(t_list *env_lst, char *str)
{
	t_env_var content_env;
	t_list	*lst_env;
	t_env_var *tmp;

	content_env.key = str;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	if (lst_env == NULL)
		return (NULL);
	tmp = lst_env->content;
	return (tmp->value);
}

/*
** Makes a copy of the environment variables of the host on which the
** program is executed and stores this copy in a list.
*/

t_list	*build_env_lst(char **env)
{
	t_list *list;
	char *tmp;

	list = NULL;
	if (env)
	{
		while(*env)
		{
			env_var_add_str(*env, &list);
			env++;
		}
		//check_existence_environment(list); TODO the SHLVL stuff
	tmp = get(list, "SHLVL");
	if (tmp == NULL)
		env_var_add_str("SHLVL=1", &list);
	tmp = get(list, "PWD");
	if (tmp == NULL)
		env_var_add_str("PWD=./", &list);
	tmp = get(list, "OLDPWD");
	if (tmp == NULL)
		env_var_add_str("OLDPWD=./", &list);
//	tmp = get(list, "HOME");
//	if (tmp == NULL)
//		env_var_add_str("HOME=not", &list);
	}
	else
		;//TODO BASH creates PWD, SHLVL and _
	return (list);
}