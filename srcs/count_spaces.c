/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:09:26 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/22 19:44:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_spaces(char *line)
{
	char	*aux;
	char	c;

	aux = line;
	c = *aux;
	while (c != 0 && is_space(c))
	{
		aux++;
		c = *aux;
	}
	return (aux - line);
}
