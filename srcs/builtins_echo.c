/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/24 03:19:58 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	builtint_echo(char **argv, char **env);

int	main(void)
{
	char *argv[10];
	char *env[1];

	env[0] = NULL;
	argv[0] = "echo";
	argv[1] = "-n";
	argv[2] = "hola";
	argv[3] = "-n";
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
	if (strcmp(argv[1], "-n") == 0)
	{
		flag_n++;
		i++;
		while (strcmp(argv[i], "-n") == 0)
			i++;
	}
	while (argv[i + 1] != NULL)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("%s", argv[i]);
	if (flag_n > 0)
		printf("\n");
}
