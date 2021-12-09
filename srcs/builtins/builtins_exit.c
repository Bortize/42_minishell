/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:55 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/09 13:09:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_exit(char **argv)
{
	unsigned char	exit_sts;
	char			*str_end;

	ft_putstr_fd("exit\n", 2);
	exit_sts = 0;
	if (!argv || argv[1] == NULL)
		exit(0);
	else
	{
		errno = 0;
		exit_sts = (unsigned char)ft_strtoi(argv[1], &str_end);
		if (errno || *str_end)
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		if (argv[2] != NULL)
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			if (g_child)
				exit(1);
			return (1);
		}
		exit(exit_sts);
	}
}
