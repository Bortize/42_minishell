/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:03:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/17 00:01:03 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Joins the key, the equals symbol and the value of
** the 't_env_var' structure in the same string.
** Returns a new string.
*/

static char	*env_node_to_str(t_env_var *envar)
{
	char	*tmp;
	char	*ret;
	char *aux;
	char *ptr;

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
** Reserves memory for the entire array of 'char *' and assigns
** to each position a string, which is the result of joining the
** key and the value of the environment.
*/

int ft_strlen_matrix(char **str);// Añadir a la libft



static char	**env_list_to_array(t_list *str_lst)
{
	const int	len = ft_lstsize(str_lst);
	char			**str_arr;
	int				i;

	str_arr = malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (str_arr);
	i = 0;
	while (str_lst)
	{
		str_arr[i] = env_node_to_str(str_lst->content);// Esta te devuelve la cadena de cada posicion en char *
		str_lst = str_lst->next;
		i++;
	}
	str_arr[i] = NULL;
	//                                Aqui deberias de meter una funcion que te ponga comillas en cada cadena
	return (str_arr);
}


static int	insert(t_list **env_lst, char **str_args)
{
	int	i;
	int	len;

	i = 1;
	while (str_args[i])
	{
		len = read_variable(str_args[i]);
		if (str_args[i][len] != '=')
			return (-1);
		env_var_add_str(str_args[i], env_lst);
		i++;
	}
	return (0);
}

/*
** Check that the export command takes arguments. If so, it exports the
** variable passed to it. Otherwise, it only prints the environment.
*/


int	builtins_export(t_list **env_lst, char **str_args)
{
	int i;
	char **aux;

	i = 1;
	if (i < 2)
	{
		aux = env_list_to_array(*env_lst);
		sort(aux);
		ft_free_arr((void **)aux);
	}
	else if (read_variable(str_args[1]) == 0)
		return (-1);
	else
		return (insert(env_lst, str_args));
	return (0);
}
