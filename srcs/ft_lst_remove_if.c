/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:35:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/15 17:35:44 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	remove_head_if(t_list **lst, void *data_ref, int (*cmp)(),
		void (*free_fun)(void *))
{
	t_list	*head;
	t_list	*garbage;

	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head && cmp(head->content, data_ref) == 0)
	{
		garbage = head;
		head = head->next;
		free_fun(garbage->content);
		free(garbage);
	}
}

void	ft_lst_remove_if(t_list **lst, void *data_ref, int (*cmp)(),
		void (*free_fun)(void *))
{
	t_list	*iter;
	t_list	*prev;

	remove_head_if(lst, data_ref, cmp, free_fun);
	if (!lst || !*lst)
		return ;
	prev = *lst;
	iter = prev->next;
	while (iter)
	{
		if (cmp(iter->content, data_ref) == 0)
		{
			prev->next = iter->next;
			free_fun(iter->content);
			free(iter);
		}
		else
			prev = prev->next;
		iter = prev->next;
	}
}
