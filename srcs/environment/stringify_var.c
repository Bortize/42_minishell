/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringify_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:32:04 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/09 15:50:05 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*stringify_var(t_env_var *var)
{
	const size_t	key_len = ft_strlen(var->key);
	size_t			val_len;
	char			*str_env;

	val_len = 0;
	if (var->value)
		val_len = ft_strlen(var->value);
	str_env = malloc((char)(key_len + val_len + 2));
	if (!str_env)
		return (NULL);
	ft_strcpy(str_env, var->key);
	str_env[key_len] = '=';
	ft_strcpy(str_env + key_len + 1, var->value);
	str_env[key_len + val_len + 1] = '\0';
	return (str_env);
}
