/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:53:11 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/21 12:12:59 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_var_cmp(void *elem1, void *elem2)
{
	const t_env_var	*ev1 = elem1;
	const t_env_var	*ev2 = elem2;

	if (ev1 == ev2 || (ev1 && ev2 && ev1->key == ev2->key))
		return (0);
	else if (!ev1->key || !ev2->key)
		return (1);
	return (ft_strcmp(ev1->key, ev2->key));
}
