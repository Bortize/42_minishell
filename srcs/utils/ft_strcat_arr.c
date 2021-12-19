/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:14:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/11 21:35:31 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//A non-NULL content-ed list is assumed.
char	*ft_strcat_arr(t_list *str_lst)
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
