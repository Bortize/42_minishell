/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:59:28 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/12 23:05:24 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Converts all str tokens into a single storing for printing with
** the line break at the end of the line
** @ **str -> Matrix of tokens
** @ *aux -> Pointer that receives the result of joining tokens
** @ *aux_free -> Reference pointer to the first string before space
** @ *aux_free_space -> Reference pointer to the second string after space
*/

void	print_echo_str(char **str)
{
	char	*aux;
	char	*aux_free;
	char	*aux_free_space;
	int		i;
	int		flag_n;

	flag_n = 0;
	aux = "\0";
	aux = ft_strjoin(aux, "");
	i = 1;
	if (strcmp(str[i], "-n") == 0)
	{
		flag_n++;
		i++;
		while (strcmp(str[i], "-n") == 0)
			i++;
	}
	while (str[i])
	{
		aux_free = aux;
		aux = ft_strjoin(aux, str[i]);
		aux_free_space = aux;
		aux = ft_strjoin(aux, " ");
		i++;
		free(aux_free);
		free(aux_free_space);
	}
	printf("%s", aux);
	if (flag_n == 0)
		printf("\n");
	free(aux);
}
