/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:19:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/13 18:54:06 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints the directory where the prompt is located using the getcwd function
*/

int	builtint_pwd(char *str)
{
	char	cwd[PATH_MAX];

	if (str != NULL)
	{
		printf("%s\n", getcwd(cwd, 4096));
		return (0);
	}
	else
		return (-1);
}
