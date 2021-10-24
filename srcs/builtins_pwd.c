/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:19:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/24 02:49:00 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>// for the PATH_MAX. if not allowed to use, replace with value 4096

void	builtint_pwd(char **argv, char **env);

int	main(void)
{
	char *argv[2];
	char *env[1];

	env[0] = NULL;
	argv[0] = "pwd";
	argv[1] = "-P";
	builtint_pwd(argv, env);
}

void	builtint_pwd(char **argv, char **env)
{
	char cwd[PATH_MAX];

	if (argv[0] != NULL)
		printf("%s\n", getcwd(cwd, 4096));
}
