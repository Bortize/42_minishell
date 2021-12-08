/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:35:32 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/08 21:40:40 by vicmarti         ###   ########.fr       */
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

	list = NULL;
	if (env)
	{
		while(*env)
		{
			env_var_add_str(*env, &list);
			env++;
		}
		//check_existence_environment(list); TODO the SHLVL stuff
	}
	else
		;//TODO BASH creates PWD, SHLVL and _
	return (list);
}
