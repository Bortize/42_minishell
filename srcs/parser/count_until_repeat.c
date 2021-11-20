/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_until_repeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:30:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/17 18:15:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//We assume line points to a non-empty string.

size_t	count_until_repeat(char *line)
{
	char	*end;
	char	c;
	char	aux;

	c = *line;
	end = line + 1;
	aux = *end;
	while (aux && aux != c)
	{
		end++;
		aux = *end;
	}
	if (aux == 0)
		return (1);
	return (end - line + 1);
}
