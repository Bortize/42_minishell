/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:03:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/10 23:49:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints the environment in the same way as the 'print_env' function
** does, adding 'declare -x' in addition.
*/

static void print_env_export(void *content)
{
	t_env_var *env_item;

	env_item = content;
	write(1, "declare -x ", 11);
	printf("%s=", env_item->key);
	printf("%s\n", env_item->value);
}

/*
** Check that the export command takes arguments. If so, it exports the
** variable passed to it. Otherwise, it only prints the environment
*/

int	builtins_export(t_list **env_lst, char **str_args)
{
	(void)env_lst;
	int i;
	int len;

	len = 0;
	i = 1;
	while (str_args[i])
	{
		printf("%s\n", str_args[i]);
		i++;
	}
	if (i < 2)
		ft_lstiter(*env_lst, print_env_export);
	else if (read_variable(str_args[1]) == 0)
		return (-1);
	else
	{
		len = read_variable(str_args[1]);
		if(!(ft_strcmp(&str_args[1][len], "=") == 0))
			return (-1);
		env_var_add_str(str_args[1], env_lst);
	}
	return (0);
}
