/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:03:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 18:08:50 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This function is part of the sort function, its task is to
** technically sort the strings and print them.
*/

static void	sort(char **str, int len)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	while (j < len)
	{
		i = j + 1;
		while (i < len)
		{
			if (ft_strcmp(str[j], str[i]) > 0)
			{
				temp = str[j];
				str[j] = str[i];
				str[i] = temp;
			}
			i++;
		}
		j++;
	}
}

/*
** Sorts an array of strings based on the comparison of their ASCII values
*/

void	sort_and_print(char **str)
{
	int		i;
	char	**sorted;
	int		len;

	len = ft_strlen_matrix(str);
	sorted = malloc(sizeof(char *) * len + 1);
	i = 0;
	while (i < len)
	{
		sorted[i] = str[i];
		i++;
	}
	sort(sorted, len);
	i = 0;
	while (i < len)
	{
		ft_putstr_fd(sorted[i], 1);
		write(1, "\n", 1);
		i++;
	}
	free(sorted);
}

/*
** Inserts the value of the variable that is being exported.
*/

static int	insert(t_list **env_lst, char **argv)
{
	int	i;
	int	len;
	int status;

	status = 0;
	i = 1;
	while (argv[i])
	{
		len = read_variable(argv[i]);
		if (argv[i][len] != '=' || argv[i][0] == '?' || len <= 0)
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(" not a valid identifier\n", 2);
			status = 1;
		}
		else
			env_var_add_str(argv[i], env_lst);
		i++;
	}
	return (status);
}

/*
** Check that the export command takes arguments. If so, it exports the
** variable passed to it. Otherwise, it only prints the environment.
*/

int	builtins_export(char **argv, t_list **env_lst)
{
	char	**aux;

	if (argv[1] == NULL)
	{
		aux = env_lst_to_array(*env_lst);
		sort_and_print(aux);
		ft_free_arr((void **)aux);
	}
	else
		return (insert(env_lst, argv));
	return (0);
}
