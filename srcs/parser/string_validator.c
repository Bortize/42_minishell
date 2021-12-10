/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:43:25 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/10 22:36:26 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int string_validator(char *line)
{
	if (string_validator_quotes(line) == 0
			|| !string_validator_pipes(line)
			|| !string_validator_redir(line))
	{
		return (0);
	}
	return (1);
}
