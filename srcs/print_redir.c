/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 04:37:46 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/29 05:09:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_type(t_behavior type)
{
	if (type == redir_out)
		printf("Output redirect\n");
	else if (type == redir_out_append)
		printf("Append redirect\n");
	else if (type == redir_in)
		printf("Input redirect\n");
	else if (type == here_doc)
		printf("Here-doc\n");
}

void	print_redir(void *elem)
{
	t_redirect	*redir;

	redir = (t_redirect *)elem;
	printf("%s as ->", redir->text);
	print_type(redir->type);
}
