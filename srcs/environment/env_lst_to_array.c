/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:27:38 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 15:52:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Joins the key, the equals symbol and the value of
** the 't_env_var' structure in the same string.
** Returns a new string.
*/

static char	*env_node_to_str(t_env_var *envar)
{
	char	*tmp;
	char	*ret;
	char	*aux;
	char	*ptr;

	ptr = ft_strdup("declare -x ");
	ret = ft_strjoin(ptr, envar->key);
	if (!ret)
		return (NULL);
	free(ptr);
	tmp = ft_strjoin(ret, "=\"");
	if (!tmp)
		return (NULL);
	free(ret);
	aux = ft_strjoin(tmp, envar->value);
	free(tmp);
	ret = ft_strjoin(aux, "\"");
	free(aux);
	return (ret);
}

/*
** Allocates memory for the entire array of 'char *' and assigns
** to each position a string, which is the result of joining the
** key and the value of the environment.
*/

char	**env_lst_to_array(t_list *str_lst)
{
	char	**str_arr;
	int		i;
	int		len;

	len = ft_lstsize(str_lst);
	str_arr = malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (str_arr);
	i = 0;
	while (str_lst)
	{
		str_arr[i] = env_node_to_str(str_lst->content);
		str_lst = str_lst->next;
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
