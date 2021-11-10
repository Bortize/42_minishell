/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chld_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:40:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/10 14:45:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

//Child processes set their handlers to SIG_DFL after execve.
//Or keep the SIG_IGN if at SIG_IGN.
//This should be useless when called on children before execve.
void	set_chld_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
