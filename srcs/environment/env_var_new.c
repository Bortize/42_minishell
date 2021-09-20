/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:00:51 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/20 12:37:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*env_var_new(char *key_str, char *value_str)
{
	t_env_var	*node;

	node = ft_calloc(1, sizeof(t_env_var));
	if (!node)
		return (NULL);
	node->key = key_str;
	node->value = value_str;
	return (node);
}
