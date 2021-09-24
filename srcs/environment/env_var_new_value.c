/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_new_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:23:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/20 12:36:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env_var_new_value(t_env_var *node, char *new_val)
{
	if (!node)
		return ;
	free(node->value);
	node->value = new_val;
}
