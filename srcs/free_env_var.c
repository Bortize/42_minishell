/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:52:01 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/12 09:55:40 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_env_var(void *ptr)
{
	t_env_var *env_aux;

	env_aux = ptr;
	free(env_aux->key);
	free(env_aux->value);
	free(env_aux);
}