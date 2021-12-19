/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_msh_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:38:36 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 20:35:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <signal.h>

void	set_msh_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
