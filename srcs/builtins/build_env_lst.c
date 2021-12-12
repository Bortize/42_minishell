/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:35:32 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/12 21:13:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	tmp = get_current_path(list, "SHLVL");
	if (tmp == NULL)
		env_var_add_str("SHLVL=1", &list);
	tmp = get_current_path(list, "PWD");
	if (tmp == NULL)
		env_var_add_str("PWD=./", &list);
	tmp = get_current_path(list, "OLDPWD");
	if (tmp == NULL)
		env_var_add_str("OLDPWD=./", &list);
	}
	else
		;//TODO BASH creates PWD, SHLVL and _
	return (list);
}
