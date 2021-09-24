/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:43:25 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/09/24 14:19:37 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int string_validator(char *line)
{
	if (!string_validator_pipes(line))
		return (0);
	return (1);
///	string_validator_spaces();
//	string_validator_etc();
} 
