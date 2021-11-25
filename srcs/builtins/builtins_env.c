/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:25:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/25 02:33:18 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ===========================================================================

/*
** Copies the environment variables of an array so as not to modify the
** originals and prints the copy on the screen.
** Need free();
*/

static void	*env_var_struct(char *key_str, char *value_str)
{
	t_env_var	*node;

	node = ft_calloc(1, sizeof(t_env_var));
	if (!node)
		return (NULL);
	node->key = key_str;
	node->value = value_str;
	return (node);
}
// ===========================================================================
static void *asign_env_struct(char *line_env, t_list *list, t_env_var *struct_env)
{
	char *equal;
	char *value_str;
	char *key_str;
	int len_key_str;
	int i;

	equal = ft_strchr(line_env, '=');
	value_str = ft_strdup(equal + 1);
	i = 0;
	while (equal != line_env)
	{
		equal--;
		i++;
	}
	len_key_str = i;
	key_str = ft_strndup(line_env, len_key_str);
	struct_env = env_var_struct(key_str, value_str);// puntero que devuelve despues de crear la estructura
//	printf("%s=", struct_env->key);
//	printf("%s\n", struct_env->value);
	if (list == NULL)
	{
		list = ft_lstnew(struct_env);
	}
	else
	{
		ft_lstadd_back(&list, ft_lstnew(struct_env));
	}
	return (list);
}

/*
** Makes a copy of the environment variables of the host on which the
** program is executed and stores this copy in a list.
*/

t_list	*builtins_env(char **env)
{
	char **ptr;// pointer for no lost the reference of **env
	int	env_count;// counter of lines for reserve memory whith malloc for matrix of env
	int i;
	t_list *list;
	t_env_var *struct_env;
	int count_node_size;

	list = NULL;
	struct_env = NULL;
	ptr = env;// For no lost the reference of pointer
	env_count = 0;
	while (*ptr != NULL)
	{
		env_count++; //counted the number of lines of env
//		printf("%i\n", env_count);// showed for screen the lines counted of env
		ptr++;
	}

	i = 0;
	while(i != env_count)
	{
		list = asign_env_struct(*env, list, struct_env);
//		asign_env_struct(*env, list, struct_env);
		env++;
		i++;
	}
	count_node_size = ft_lstsize(list);// Cuenta los nodos de la lista que se acaba de crear
//	printf("%d\n", count_node_size);// Imprime el numero de nodos de la lista
	check_existence_environment(list);
//	ft_lstiter(list, print_env);
	return (list);
}
//
