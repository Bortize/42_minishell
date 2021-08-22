/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_syntactic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:33:04 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 20:45:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO Maybe move to libft
static size_t	count_char(char c, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

//TODO (1): Pipes separate commands rather than tokens. A Command list that
//holds tokens in it could be a way to orginize data.
//If so, the parser could use some rethinking.
size_t	read_syntactic(char *text, t_token *tk)
{
	size_t	i;

	tk->behavior = plain;
	i = count_char(' ', text);
	if (ft_strncmp(text + i, ">>") == 0)
	{
		tk->behavior = append;
		return (i + 2);
	}
	else if (ft_strncmp(text + i, "<<") == 0)
	{
		tk->behavior = here_doc;
		return (i + 2);
	}
	else if (text[i] == '>')
	{
		tk->behavior = redir_out;
		return (i + 1);
	}
	else if (text[i] == '<')
	{
		tk->behavior = redir_in;
		return (i + 1);
	}
	else if (text[i] == '|') //1
	{
		tk->behavior = pipe;
		return (i + 1);
	}
	return (i);
}
