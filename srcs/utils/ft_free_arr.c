/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:43:41 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 15:46:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_free_arr(void **ptr_arr)
{
	size_t	i;

	i = 0;
	while (ptr_arr[i])
	{
		free(ptr_arr[i]);
		i++;
	}
	free(ptr_arr);
}
