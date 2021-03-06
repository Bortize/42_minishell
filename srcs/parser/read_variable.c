/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:49:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 10:49:56 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Checks that the first character of the string it receives is not a number,
**	in which case it returns zero. Otherwise, it returns the length of the string.
**	Since $? is a variable, that's included as well.
*/

size_t	read_variable(char *text)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(text[i]))
		return (0);
	if (text[i] == '?')
		return (1);
	while (ft_isalnum(text[i]) || text[i] == '_')
		i++;
	return (i);
}
