/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:05:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/19 20:24:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_pipe(char *line, int *pipe, int *text)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			*pipe = 1;
			if (!text)
				break ;
			*text = 0;
		}
		else if (line[i] != ' ')
			*text = 1;
		i++;
	}
}

int	string_validator_pipes(char *line)
{
	int	text;
	int	pipe;

	text = 0;
	pipe = 0;
	check_pipe(line, &pipe, &text);
	if (pipe && !text)
	{
		ft_putstr_fd("parse error near `|'\n", 2);
		return (0);
	}
	return (1);
}
