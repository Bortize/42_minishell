/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:23:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/17 22:08:20 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	builtins_unset(char **argv, t_list **env_lst)
{
	t_env_var	ref;
	int			status;

	status = 0;
	argv++;
	while (*argv)
	{
		if (read_variable(*argv) != ft_strlen(*argv) || **argv == '?')
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(*argv, 2);
			ft_putstr_fd(" not a valid identifier\n", 2);
			status = 1;
		}
		else
		{
			ref.key = *argv;
			ref.value = NULL;
			ft_lst_remove_if(env_lst, &ref, env_var_cmp,
				(void (*)(void *))env_var_delete);
		}
		argv++;
	}
	return (status);
}
