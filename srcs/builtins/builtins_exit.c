/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:55 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 17:30:49 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_num(char *text)
{
	char	*str_end;
	int		num;

	errno = 0;
	num = (unsigned char)ft_strtoi(text, &str_end);
	if (errno || *str_end)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(text, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		num = 255;
	}
	return (num);
}

int	builtins_exit(char **argv, t_list **env_lst)
{
	unsigned char	exit_sts;

	(void)env_lst;
	if (!(g_status & STS_IS_CHILD))
		ft_putstr_fd("exit\n", 2);
	exit_sts = 0;
	if (!argv || argv[1] == NULL)
		exit_sts = 0;
	else if (argv[2] != NULL)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		if (!(g_status & STS_IS_CHILD))
			return (1);
		exit_sts = 1;
	}
	else
		exit_sts = (char)validate_num(argv[1]);
	exit(exit_sts);
}
