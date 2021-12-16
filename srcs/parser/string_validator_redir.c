/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:03:20 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 20:38:43 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//Quoting has been validated.
int	string_validator_redir(char *line)
{
	int	token_expected;

	token_expected = 0;
	while (*line && !(token_expected && is_delimiter(*line)))
	{
		token_expected = 0;
		if (*line == '\'' || *line == '\"')
			line += count_until_repeat(line) - 1;
		else if (*line == '<' || *line == '>')
		{
			token_expected = 1;
			if (*(line + 1) == *line)
				line++;
		}
		line++;
		while (*line && ft_isspace(*line))
			line++;
	}
	if (token_expected)
		ft_putstr_fd("Parser error: expected token after redirection.\n", 2);
	return (!token_expected);
}
