/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:57:36 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 18:57:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/libft.h>
#include <stdio.h>
#include "minishell.h"
//TODO I'm adding this to the libft.


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

/*
** Release the Peoria a vector
*/

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

int ft_strlen_matrix(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int sort(char **arreglo)
{
		int i;
		int j;
		char **sorted;
		int d;

		d = ft_strlen_matrix(arreglo);
		sorted = malloc(sizeof(char *) * d + 1);

		i = 0;
		while (i < d)
		{
				sorted[i] = arreglo[i];
				i++;
		}
		j = 0;
		while (j < d)
		{
				i = j + 1;
				while (i < d)
				{
						if (strcmp(sorted[j], sorted[i]) > 0)
						{
								char *temp = sorted[j];
								sorted[j] = sorted[i];
								sorted[i] = temp;
						}
						i++;
				}
			j++;
		}
		i = 0;
		while (i < d)
		{
				printf("%s\n",sorted[i]);
				i++;
		}
		// FREEEEEE
//		ft_free_arr((void **) sorted);
		return (0);
	}
