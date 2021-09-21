/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:09:26 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/21 08:05:34 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_spaces(char *line)
{
	char	*end;
	char	aux;

	aux = *line;
	end = line;
	while (aux && is_space(aux))
	{
		end++;
		aux = *end;
	}
	return (end - line);
}
