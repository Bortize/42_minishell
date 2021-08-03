/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:09:01 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 17:15:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

t_token	*add_token(t_token **token_list, char *text, t_behavior behavior)
{
	t_token	*new_token;
	t_token	*iterator;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->next = NULL;
	new_token->behavior = behavior;
	new_token->text = text;
	iterator = *token_list;
	if (!iterator)
	{
		*token_list = new_token;
		return (new_token);
	}
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new_token;
	return (new_token);
}
