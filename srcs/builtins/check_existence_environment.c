/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existence_environment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:14 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/25 02:59:38 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_existence_environment(t_list *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

	shelevelref.key = "PATH";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(str, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	printf("%s\n",tmp->key);
	if (ft_strcmp(tmp->key,shelevelref.key) == 0)
		printf("TODO EN ORDEN, LA ENV ESTABA PRESENTE\n");
	else
		printf("CAGADA, TE TOCA AÑADIR LA ENV...PUTA BIDA\n");
//	printf("--------------->>>%s\n", tmp->value);
/*
	if (ft_strcmp(tmp, shelevelref.key) == 0)
	{
		printf("ENCONTRADO \n");
	}
	else
	{
		printf("Lo siento macho \n");
	}
*/
}
