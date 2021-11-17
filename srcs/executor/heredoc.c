/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:27:57 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/16 13:20:08 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	wait_input(char *eof, int ignore_input)
{
	char	*line;

	line = readline("<< ");
	while (line && ft_strmcp(line, eof) != 0)
	{
		if (!ignore_input)
			write(1, line, ft_strlen(line));
		free(line);
		line = readline("<< ");
	}
}

void	heredoc(t_list *input_redirs)
{
	t_redirect	*redir_data;

	if (!input_redirs)
		return ;
	while (input_redirs->next)
	{
		redir_data = (t_redirect *)(input_redirs->content)
		if (redir_data->type == here_doc)
			wait_input(redir_data->text, 1);
		input_redirs = input_redirs->next;
	}
	if (redir_data->type == here_doc)
		wait_input(redir_data->text, 0);
}
