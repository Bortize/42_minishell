/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:23:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/08 16:51:00 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_lst_remove_if(t_list **lst, void *data_ref, int (*cmp)(),
		void (*free_fun)(void *))
{
	t_list	*iter;
	t_list	*prev;

	prev = *lst;
	if (!*lst)
		return ;
	while (cmp(prev->content, data_ref) == 0)
	{
		free_fun(iter->content);
		iter = prev;
		prev = prev->next;
		free(iter);
	}
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

int	builtins_unset(t_list **env_lst, char **str_args)
{
	t_env_var	ref;

	str_args++;
	while (*str_args)
	{
		ref.key = *str_args;
		ref.value = NULL;
		ft_lst_remove_if(env_lst, &ref, env_var_cmp
				, (void (*)(void *))env_var_delete);
		str_args++;
	}
	return (0);
}
