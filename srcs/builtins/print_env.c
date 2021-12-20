/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:31 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 13:32:18 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void *content)
{
	t_env_var	*env_item;

	env_item = content;
	ft_putstr_fd(env_item->key, 1);
	write(1, "=", 1);
	ft_putstr_fd(env_item->value, 1);
	write(1, "\n", 1);
}
