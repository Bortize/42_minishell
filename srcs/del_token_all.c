/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:19:41 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 17:08:40 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_token_all(t_token **token_list)
{
	t_token	*freeme;
	t_token	*iterator;

	iterator = *token_list;
	while (iterator)
	{
		freeme = iterator;
		iterator = iterator->next;
		free(freeme->text);
		free(freeme);
	}
}
