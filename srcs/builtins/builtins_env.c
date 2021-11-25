/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:25:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/25 15:28:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Build and add a new env node to the list, we should make it smaller. //TODO
//It takes too many lines of error checking
static int	asign_env_struct(char *line_env, t_list **list)
{
	char		*equal;
	char		*value_str;
	char		*key_str;
	t_env_var	*env_var;
	t_list		*node_aux;

	equal = ft_strchr(line_env, '=');
	value_str = ft_strdup(equal + 1);
	key_str = ft_strndup(line_env, equal - line_env);
	if (!value_str || !key_str)
	{
		free(value_str);
		free(key_str);
		return (0); //TODO Error no mem
	}
	env_var = env_var_new(key_str, value_str);
	if (!env_var) //Duplicate move to sttic //TODO
	{
		free(value_str);
		free(key_str);
		return (0); //TODO Error no mem
	}
	node_aux = ft_lstnew(env_var);
	if (!node_aux)
	{
		free(env_var);
		free(value_str);
		free(key_str);
		return (0); //TODO Error no mem
	}
	ft_lstadd_back(list, node_aux);
	return (1);
}

/*
** Makes a copy of the environment variables of the host on which the
** program is executed and stores this copy in a list.
*/

t_list	*build_env_lst(char **env)
{
	t_list *list;

	list = NULL;
	if (!env)
		return (list); //TODO Perhaps add some custom env of our own.
	while(*env)
	{
		if (!asign_env_struct(*env, &list))
		{
			ft_lstclear(&list, free);//TODO will leak, use custom fcton to free
			return (NULL); //TODO Error no mem
		}
		env++;
	}
	//check_existence_environment(list); TODO the SHLVL stuff
	return (list);
}
