/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:16:23 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/13 19:39:28 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env_var	*env_var_find(t_list *env_lst, char *key)
{
	t_env_var	data_ref;
	t_list		*target;

	data_ref.key = key;
	data_ref.value = NULL;
	target = ft_lst_find(env_lst, &data_ref, env_var_cmp);
	if (!target)
		return (NULL);
	return (target->content);
}
