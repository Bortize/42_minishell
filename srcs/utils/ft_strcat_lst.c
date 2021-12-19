/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:35:58 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 20:42:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strcat_lst(t_list *str_lst)
{
	char	*aux;
	char	*str;

	if (!str_lst || !(str_lst->content))
		return (NULL);
	str = ft_strdup(str_lst->content);
	while (str_lst->next)
	{
		str_lst = str_lst->next;
		if (!(str_lst->content))
			return (str);
		aux = str;
		str = ft_strjoin(aux, str_lst->content);
		free(aux);
		if (!str)
			return (NULL);
	}
	return (str);
}
