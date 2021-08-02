/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:22:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/02 22:08:10 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define RAW 1
#define DQUOTES 2
#define LITERAL 3


void	tokenize(t_token **tk_list, char *line)
{
	size_t	i = 0;
	size_t	word_size = 0;
	t_token	*last_tk;
	char	mode = RAW;

	add_front_token(tk_list);
	last_tk = *tk_list;
	while (line[i])
	{
		if (read_as_metacharacter(line[i], mode))
			apply_metacharacter(line[i], &mode, tk_list);
		else
			word_size++;
		i++;
	}
}

