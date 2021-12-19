/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:48:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 14:48:47 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Searches each node of a list for the contents passed by parameter, where:
** @ t_list *lst -> This is the list in where go to search the data.
** @ void *data_ref -> This is the reference to compare (here is t_env_var)
** @ int (*cmp(void *, void *)) -> This is your own function that have to compare
*/

t_list	*ft_lst_find(t_list *lst, void *data_ref, int (*cmp)(void *, void *))
{
	int	i;
	int	p;

	p = ft_lstsize(lst);
	i = 0;
	while (i < p)
	{
		if (cmp(data_ref, lst->content) == 0)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
