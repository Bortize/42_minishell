/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:35:58 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/11 22:00:09 by vicmarti         ###   ########.fr       */
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
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
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
