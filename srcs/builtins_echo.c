/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/22 19:26:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	builtint_echo(char **argv, char **env);

int	main(void)
{
	char *argv[5];
	char *env[1];

	env[0] = NULL;
	argv[0] = "echo";
	argv[1] = NULL;
	argv[2] = "hello";
	argv[3] = "texto";
	argv[4] = NULL;
	builtint_echo(argv, env);
}

void	builtint_echo(char **argv, char **env)
{
	int i;
	int flag_n;

	i = 1;
	if (argv[i] == NULL)
	{
		printf("\n");
		return;
	}
	if ((strcmp(argv[1], "-n") == 0))
	{
		flag_n++;
		i++;
	}
	while (argv[i + 1] != NULL)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("%s", argv[i]);
	if (flag_n != 1)
		printf("\n");
}
