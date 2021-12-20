/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:59:28 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 16:54:00 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Count all the '-n' to advance the iterate to the part where
** the printed text begins.
*/

static void	remove_endline(char **str, int *i)
{
	(*i)++;
	while (str[*i] && ft_strcmp(str[*i], "-n") == 0)
		(*i)++;
}

/*
** Concatenates all tokens into a single string
*/

static char	*join_args(char **str, int i)
{
	char	*aux;
	char	*aux_free;
	char	*aux_free_space;

	aux = ft_strdup("");
	while (str[i])
	{
		aux_free = aux;
		aux = ft_strjoin(aux, str[i]);
		aux_free_space = aux;
		aux = ft_strjoin(aux, " ");
		i++;
		free(aux_free);
		free(aux_free_space);
	}
	return (aux);
}

/*
** Converts all str tokens into a single storing for printing with
** the line break at the end of the line
** @ **str -> Matrix of tokens
** @ *aux -> Pointer that receives the result of joining tokens
** @ *aux_free -> Reference pointer to the first string before space
** @ *aux_free_space -> Reference pointer to the second string after space
*/

int	builtins_echo(char **argv, t_list **env_lst)
{
	char	*aux;
	int		i;

	(void)env_lst;
	i = 1;
	if (argv[i] && strcmp(argv[i], "-n") == 0)
		remove_endline(argv, &i);
	aux = join_args(argv, i);
	printf("%.*s", (int)ft_strlen(aux) - 1, aux);
	if (i == 1)
		printf("\n");
	free(aux);
	return (0);
}
