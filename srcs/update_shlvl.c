/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:22:18 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/08 20:15:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Searches the linked list of environment variables for the key HOME to
** obtain its value and return it as a return.
** @ content_env -> Node contents of the environment variable list
** @ lst_env -> environment variable list
** @ tmp ->
*/

static char	*get(t_list *env_lst, char *str)
{
	t_env_var content_env;
	t_list	*lst_env;
	t_env_var *tmp;

	content_env.key = str;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	tmp = lst_env->content;
	return (tmp->value);
}

/*
** Search 'env_lst' for the key to update its value with the path
** that the function receives as parameter.
*/

static char	*set(t_list *env_lst, char *str, char *search)
{
	t_env_var content_env;
	t_list	*lst_env;
	t_env_var *tmp;

	content_env.key = search;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	tmp = lst_env->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	printf("🍏 %s\n", tmp->value);
	return (tmp->value);
}

int	update_shlvl(t_list *env_lst)
{
	int p;
	char *c;

	printf("🍉%s\n", get(env_lst, "SHLVL"));
	// 1. Recojo el valor de lst_env -> SHLVL
	c = get(env_lst, "SHLVL");
	// 2. Convierto el valor de char a entero.
	p = ft_atoi(c);
	// 3. Le sumo el valor de 1
	if (p < 1)
		p = 1;
	else
		p = p + 1;
	// 4. Convierto el valor de entero a char
	c = ft_itoa(p);
	// 5. seteo el nuevo valor en lst_env -> SHLVL
	set(env_lst, c, "SHLVL");
//	printf("🌽 %s\n", get(env_lst, "SHLVL"));
	free(c);
	return (0);
}