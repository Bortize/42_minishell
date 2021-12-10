/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:19:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/10 23:03:51 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>// for the PATH_MAX. if not allowed to use, replace with value 4096

int	builtint_pwd(char *str)
{
	char cwd[PATH_MAX];

	if (str != NULL)
	{
		printf("%s\n", getcwd(cwd, 4096));
		return (0);
	}
	else
		return (-1);
}
