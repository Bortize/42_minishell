/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:06:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/22 19:14:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	return (ft_strchr(" \t", c) != NULL);
}