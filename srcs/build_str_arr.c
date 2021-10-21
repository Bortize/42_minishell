/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:57:36 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/21 14:03:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//TODO honestly this only needs include <libft.h>

char	**build_str_arr(t_list *str_lst)
{
	const int	len = ft_lstsize(str_lst);
	char	**str_arr;

	str_arr = malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (str_arr);
	str_arr[len] = NULL;
	while (str_lst)
	{
		*str_arr = str_lst->content;
		str_arr++;
		str_lst = str_lst->next;
	}
	return (str_arr);
}
