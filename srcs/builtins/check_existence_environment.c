/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existence_environment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:14 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/24 21:19:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_existence_environment(t_list *str)
{
	t_env_var shelevelref;
	t_list	*found_shlvl;
	t_env_var *tmp;

//	if ()
	shelevelref.key = "TER";
	shelevelref.value = NULL;
	found_shlvl = ft_lst_find(str, &shelevelref, env_var_cmp);
	tmp = found_shlvl->content;
	printf("-----FOUND--------->>>%s\n", tmp->key);//TODO --> seg.fault when the env dont exist
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
