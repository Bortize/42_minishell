/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_msh_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:38:36 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/10 15:15:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> //TODO maybe just make iot smaller
#include <signal.h>

void	set_msh_signals(void)
{
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
}
