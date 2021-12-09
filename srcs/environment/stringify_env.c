/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringify_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:22:50 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/09 15:50:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**stringify_env(t_list *env)
{
	const int	len = ft_lstsize(env);
	char		**str_arr;
	int			i;

	str_arr = malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (NULL);
	str_arr[len] = NULL;
	i = 0;
	while (env)
	{
		str_arr[i] = stringify_var((t_env_var *)(env->content));
		if (str_arr[i] == NULL)
		{
			while (i-- > 0)
				free(str_arr[i]);
			free(str_arr);
			return (NULL);
		}
		env = env->next;
		i++;
	}
	return (str_arr);
}
