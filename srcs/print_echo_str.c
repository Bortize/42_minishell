/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:59:28 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/20 16:29:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo_str(char **str)
{
	char *aux;
	char *aux_free;// para liberar el string
	char *aux_free_space;// para liberar el string con el espacio
	int i;

	aux = ft_strjoin(aux, "");
	i = 0;
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
	printf("\n%s\n", aux);
	free(aux);
}