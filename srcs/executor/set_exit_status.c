/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:12:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 21:16:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	Set the last byte of g_status to the value given (casted).
*/

void	set_exit_status(int	value)
{
	g_status &= ~0xFF;
	g_status += (unsigned char)value;
}
