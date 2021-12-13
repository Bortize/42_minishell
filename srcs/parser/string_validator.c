/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:43:25 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/13 19:38:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_validator(char *line)
{
	if (string_validator_quotes(line) == 0 || !string_validator_pipes(line))
		return (0);
	return (1);
}
