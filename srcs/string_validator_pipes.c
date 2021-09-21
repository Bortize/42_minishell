 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:05:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/21 12:50:10 by bgomez-r         ###   ########.fr       */
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
	while (line[i])
	{
		if (line[i] != " ")
			text++;
		else if (line[i] == '|')
			pipe++;
		i++;
	}
	if (pipe > 0 && text == 0)
		return (0); // TODO error because not have text in pipe
}
