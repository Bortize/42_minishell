/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:49:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 17:21:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	read_variable(char *text)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(text[i]))
		return (0);
	while (ft_isalnum(text[i]) || text[i] == '_')
		i++;
	return (i);
}
