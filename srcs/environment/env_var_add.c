/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/20 20:48:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_input(char *key, char *value)
{
	if (!key || !value)
	{
		free(key);
		free(value);
	}
	return (key && value);
}

/*
**	Modify the environment list:
**		If key or value are null, do nothing.
**		If key exists, it's value gets updated to 'value'.
**		If not, it creates a new node.
**	Frees any unused string.
*/

void	env_var_add(t_list **env_lst, char *key, char *value)
{
	t_env_var	*target;
	t_list		*node_aux;

	if (!check_input(key, value))
		return ;
	target = env_var_find(*env_lst, key);
	if (target)
	{
		free(key);
		key = NULL;
		env_var_new_value(target, value);
		return ;
	}
	target = env_var_new(key, value);
	node_aux = ft_lstnew(target);
	if (!node_aux || !target)
		perror_and_exit("FATAL", errno);
	ft_lstadd_back(env_lst, node_aux);
}
