/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:57:36 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/21 16:31:24 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/libft.h>
//TODO I'm adding this to the libft.

char	**build_str_arr(t_list *str_lst)
{
	const int	len = ft_lstsize(str_lst);
	char		**str_arr;
	int			i;

	str_arr = malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (str_arr);
	str_arr[len] = NULL;
	i = 0;
	while (str_lst)
	{
		str_arr[i] = str_lst->content;
		str_lst = str_lst->next;
		i++;
	}
	return (str_arr);
}

/*
** Searches each node of a list for the contents passed by parameter, where:
** @ t_list *lst -> This is the list in where go to search the data.
** @ void *data_ref -> This is the reference to compare (here is t_env_var)
** @ int (*cmp(void *, void *)) -> This is your own function that have to compare
*/

t_list	*ft_lst_find(t_list *lst, void *data_ref, int (*cmp)(void *, void *))
{
	while (lst)
	{
		if (cmp(data_ref, lst->content) == 0)// <<================
			break ;
		lst = lst->next;
	}
	return (lst);
}

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

t_list	*ft_lst_at(t_list *lst, size_t pos)
{
	while (lst && pos > 0)
	{
		pos--;
		lst = lst->next;
	}
	return (lst);
}
