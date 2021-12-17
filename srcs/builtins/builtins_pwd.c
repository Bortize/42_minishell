/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:19:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/17 23:03:07 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints the directory where the prompt is located using the getcwd function
*/

int	builtins_pwd(char **argv, t_list **env_lst)
{
	char	*str;

	(void)argv;
	(void)env_lst;
	str = getcwd(NULL, -4987);
	if (!str)
	{
		perror("PWD");
		return ((char)errno);
	}
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
	return (0);
}
