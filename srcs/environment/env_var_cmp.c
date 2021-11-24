/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:53:11 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/24 21:05:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This function receives 2 void pointers as parameters and compares their
** values. Here we will use it to compare the values of 2 structures of
** type t_env_var where:
** @ void *elem1 -> Pointer to structure of type t_env_var (shelevelref)
** @ void *elem2 -> Pointer to structure of type t_env_var (lst->content)
*/

int	env_var_cmp(void *elem1, void *elem2)

{
	const t_env_var	*ev1 = elem1;
	const t_env_var	*ev2 = elem2;

	if (ft_strcmp(ev1->key, ev2->key) == 0)
		return (0);
	else
		return (1);
}
