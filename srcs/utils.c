/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:57:42 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 22:35:53 by vicmarti         ###   ########.fr       */
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
