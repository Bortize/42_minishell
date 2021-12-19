/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:59:13 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 15:00:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Calculates the length of the size of a string array.
** Returns the value of its length
*/

size_t	ft_strlen_matrix(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
