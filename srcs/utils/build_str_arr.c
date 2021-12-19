/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:41:55 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 15:49:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** This function takes the arguments stored in a "t_list *arg" of the t_cmd
** structure and transforms them into an array matrix "char **argv".
** @ *str_lst -> List of arguments
** @ len -> List size
** @ **str_arr ->  Argument array
*/

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
