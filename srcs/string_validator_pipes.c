/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:05:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/20 19:27:42 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_validator_pipes(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '|')
	{
		if (line[i] == '|')
			cmd_len += count_until_repeat(line + cmd_len);
		else
			line[i++];
	}
}


if (line[i] && line[i] == " ")
	i++;