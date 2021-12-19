/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:22:18 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/19 20:24:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Searches the linked list of environment variables for the key HOME to
** obtain its value and return it as a return.
** @ content_env -> Node contents of the environment variable list
** @ lst_env -> environment variable list
** @ tmp -> content of the struct
*/

static char	*get(t_list *env_lst, char *str)
{
	t_env_var	content_env;
	t_list		*lst_env;
	t_env_var	*tmp;

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
	t_env_var	content_env;
	t_list		*lst_env;
	t_env_var	*tmp;

	content_env.key = search;
	content_env.value = NULL;
	lst_env = ft_lst_find(env_lst, &content_env, env_var_cmp);
	tmp = lst_env->content;
	free(tmp->value);
	tmp->value = ft_strdup(str);
	return (tmp->value);
}

/*
** Updates the SHLVL environment variable according to the shell
** level you are in.
*/

int	update_shlvl(t_list *env_lst)
{
	int		p;
	char	*c;

	c = get(env_lst, "SHLVL");
	p = ft_atoi(c);
	if (p < 1)
		p = 1;
	else
		p = p + 1;
	c = ft_itoa(p);
	set(env_lst, c, "SHLVL");
	free(c);
	return (0);
}
