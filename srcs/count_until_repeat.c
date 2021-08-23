/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_until_repeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:30:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/23 22:06:55 by vicmarti         ###   ########.fr       */
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
