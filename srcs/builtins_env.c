/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:25:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/05 20:32:49 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

/*
** Copies the environment variables of an array so as not to modify the
** originals and prints the copy on the screen.
** Need free();
*/

void	builtins_env(char **env, t_list *env_list)
{
	char **ptr;// pointer for no lost the reference of **env
	int	env_count;// counter of lines for reserve memory whith malloc for matrix of env
	char **filas;// for reserve memory for matrix
	char **lst_env;
	int i;
	int j;
	t_env_var	*lst_env;

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
	lst_env = env;
	i = 0;
	while(i != env_count)
	{
		*filas = strdup(*ptr);// TO DO: modify by the original function
		printf("%s\n", *filas);
		ptr++;
		printf("%p\n", filas);
		filas++;
		i++;
	}
	j = 0;
	while(j != env_count)
	{
		printf("%s\n", *lst_env);
	}
}
