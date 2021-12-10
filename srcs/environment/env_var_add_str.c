/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_add_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:17:45 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/10 19:18:44 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	Add environment variable from a string in the form KEY=VALUE
*/

void	env_var_add_str(char *line_env, t_list **list)
{
	char		*equal;
	char		*value_str;
	char		*key_str;

	equal = ft_strchr(line_env, '=');
	value_str = ft_strdup(equal + 1);
	key_str = ft_strndup(line_env, equal - line_env);
	env_var_add(list, key_str, value_str);
}
