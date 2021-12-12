/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:03:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/12 22:43:29 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints the environment in the same way as the 'print_env' function
** does, adding 'declare -x' in addition.
*/

static void	print_env_export(void *content)
{
	t_env_var	*env_item;

	env_item = content;
	write(1, "declare -x ", 11);
	printf("%s=", env_item->key);
	printf("%s\n", env_item->value);
}

static int	insert(t_list **env_lst, char **str_args)
{
	int	i;
	int	len;

	i = 1;
	while (str_args[i])
	{
		len = read_variable(str_args[i]);
		if (str_args[i][len] != '=')
			return (-1);
		env_var_add_str(str_args[i], env_lst);
		i++;
	}
	return (0);
}

/*
** Check that the export command takes arguments. If so, it exports the
** variable passed to it. Otherwise, it only prints the environment
*/

int	builtins_export(t_list **env_lst, char **str_args)
{
	int	i;

	(void)env_lst;
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
		return (insert(env_lst, str_args));
	return (0);
}
