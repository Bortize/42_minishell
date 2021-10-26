/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 07:49:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/26 13:47:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

void builtins_env(char **argv, char **env);

int	main(int argc, char **argv, char **env)
{
	builtins_env(argv, env);
	return (0);
}

/*
** Copies the environment variables of an array so as not to modify the
** originals and prints the copy on the screen.
** Need free();
*/

void	builtins_env(char **argv, char **env)
{
	char **ptr;// pointer for no lost the reference of **env
	int	env_count;// counter of lines for reserve memory whith malloc for matrix of env
	char **filas;// for reserve memory for matrix
	int i;
	t_list *env;

	ptr = env;// For no lost the reference of pointer
	env_count = 0;
	while (*ptr != NULL)
	{
		env_count++; //counted the number of lines of env
//		printf("%i\n", env_count);// showed for screen the lines counted of env
		ptr++;
	}
	filas = (char **)malloc(env_count * sizeof(char *));

	ptr = env;
	i = 0;
	while(i != env_count)
	{
		*filas = ft_strdup(*ptr);// TO DO: modify by the original function
		printf("%s\n", *filas);
		ptr++;
		filas++;
		i++;
	}
}
