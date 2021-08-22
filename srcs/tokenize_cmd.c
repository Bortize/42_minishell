/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:04:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/22 23:38:14 by vicmarti         ###   ########.fr       */
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

void	tokenize_cmd(char *cmd_txt)
{
	char		read_mode;
	t_behavior	token_behavior;
	size_t		token_start;
	size_t		i;

	read_mode = 0;
	token_behavior = plain;
	i = 0;
	token_start = i;
	//TODO The count_spaces/read_token logic to go through syntax/spaces
	//Already moves i to the next element of the string, hence I explicitly
	//increment it on the * todo-s only, plx rethink logic and structure when
	//fitting it to norm standards. It-s a --CRAPPY-- FIX. I've not gotten the
	//logic right yet.
	while (cmd_txt[i])
	{
		if (read_mode == 0)
		{
			if (cmd_txt[i] == '\'' || cmd_txt[i] == '\"')
				read_mode = cmd_txt[i++];//TODO *
			else if (is_delimiter(cmd_txt[i]))
			{
				if (i != token_start)
				{
					write(1, cmd_txt + token_start, i - token_start);
					write(1, "\n", 1);
				}
				i += count_spaces(cmd_txt + i);
				i += read_token_behavior(cmd_txt + i, &token_behavior);
				i += count_spaces(cmd_txt + i);
				token_start = i;
			}
			else
				i++; //TODO *
		}
		else if (cmd_txt[i++] == read_mode) //TODO *
			read_mode = 0;
		else
			i++; //TODO *
	}
	if (i != token_start)
	{
		write(1, cmd_txt + token_start, i - token_start);
		write(1, "\n", 1);
	}
}
