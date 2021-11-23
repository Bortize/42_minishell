/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:31 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/12 20:27:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_env(void *content)
{
	t_env_var *env_item;

	env_item = content;
	printf("%s=", env_item->key);
	printf("%s\n", env_item->value);
}