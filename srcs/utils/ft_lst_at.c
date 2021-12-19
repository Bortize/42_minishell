/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:44:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 15:47:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*ft_lst_at(t_list *lst, size_t pos)
{
	while (lst && pos > 0)
	{
		pos--;
		lst = lst->next;
	}
	return (lst);
}
