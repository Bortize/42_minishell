/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:45:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/13 19:38:24 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	string_validator_quotes(char *line)
{
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			line = ft_strchr(line + 1, *line);
			if (!line)
			{
				ft_putstr_fd("Parser error: unclosed quotes. \n", 2);
				return (0);
			}
		}
		else
			line++;
	}
	return (1);
}
