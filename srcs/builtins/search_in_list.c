/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:56:37 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/12 20:57:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (!lst_env)
		return (NULL);
	else
	{
		tmp = lst_env->content;
		return (tmp->value);
	}
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