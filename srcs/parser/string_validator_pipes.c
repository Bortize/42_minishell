 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:05:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/24 14:48:27 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_validator_pipes(char *line)
{
	int text;
	int pipe;
	int i;

	text = 0;
	pipe = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			pipe = 1;
			if (!text)
				break ; //TODO esta mal
			text = 0;
		}
		else if (line[i] != ' ')
			text = 1;
		i++;
	}
		printf("Pipe %d, text%d\n", pipe, text);
	if (pipe  && !text)
	{
		print_error("parse error near `|'"); // TODO error because not have text in pipe
		return (0);
	}
	return (1);
}
