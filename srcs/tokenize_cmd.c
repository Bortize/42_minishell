/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:04:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/23 22:05:56 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	read_token_behavior(char *line, t_behavior *type)
{
	*type = plain;
	if (line[0] == '>')
	{
		if (line[1] == '>')
		{
			*type = redir_out_append;
			return (2);
		}
		*type = redir_out;
		return (1);
	}
	else if (line[0] == '<')
	{
		if (line[1] == '<')
		{
			*type = here_doc;
			return (2);
		}
		*type = redir_in;
		return (1);
	}
	return (0);
}

//TODO Just for debug purposes.
static void	print_token(char *cmd_txt, size_t i, size_t token_start)
{
	if (i != token_start)
	{
		write(1, cmd_txt + token_start, i - token_start);
		write(1, "\n", 1);
	}
}

void	tokenize_cmd(char *cmd_txt)
{
	t_behavior	token_behavior;
	size_t		token_start;
	size_t		i;

	i = 0;
	token_start = i;
	while (cmd_txt[i])
	{
		if (cmd_txt[i] == '\'' || cmd_txt[i] == '\"')
			i += count_until_repeat(cmd_txt + i);
		else if (is_delimiter(cmd_txt[i]))
		{
			print_token(cmd_txt, i, token_start);
			i += count_spaces(cmd_txt + i);
			i += read_token_behavior(cmd_txt + i, &token_behavior);
			i += count_spaces(cmd_txt + i);
			token_start = i;
		}
		else
			i++;
	}
	print_token(cmd_txt, i, token_start);
}
