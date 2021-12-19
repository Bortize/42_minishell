/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 04:37:46 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/19 13:52:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static char	*stringify_type(t_behavior type)
{
	if (type == redir_out)
		return (">");
	else if (type == redir_out_append)
		return (">>");
	else if (type == redir_in)
		return ("<");
	else if (type == here_doc)
		return ("<<");
	return (NULL);
}

void	print_redir(void *elem)
{
	t_redirect	*redir;

	redir = (t_redirect *)elem;
	printf("%s | %s\n", stringify_type(redir->type), redir->text);
}
