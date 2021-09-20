/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:50:13 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/20 12:43:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env_var_delete(t_env_var *var)
{
	if (!var)
		return ;
	free(var->key);
	free(var->value);
	free(var);
}
