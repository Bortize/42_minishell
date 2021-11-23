/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:59:28 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/24 00:41:19 by bgomez-r         ###   ########.fr       */
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
	char *aux;
	char *aux_free;// para liberar el string
	char *aux_free_space;// para liberar el string con el espacio
	int i;

	aux = "\0";
	aux = ft_strjoin(aux, "");
	i = 1;// comienza en 1 para evitar imprimir echo
	while (str[i])
	{
		aux_free = aux;
		aux = ft_strjoin(aux, str[i]);
		aux_free_space = aux;
		aux = ft_strjoin(aux, " ");
		i++;;
		free(aux_free);
		free(aux_free_space);
	}
	printf("%s\n", aux);
	free(aux);
}
