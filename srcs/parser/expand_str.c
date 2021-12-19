/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:43:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 18:20:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*expand_str(char *str, t_list *env_lst)
{
	t_list	*expanded_tokens;
	char	*expanded_str;

	expanded_tokens = NULL;
	tokenize_expansions(&expanded_tokens, str, env_lst);
	if (!expanded_tokens)
		return (NULL);
	expanded_str = ft_strcat_lst(expanded_tokens);
	ft_lstclear(&expanded_tokens, free);
	return (expanded_str);
}
