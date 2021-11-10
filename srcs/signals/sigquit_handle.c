/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:44:47 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/10 16:01:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp

void	sigquit_handle(int sig_num)
{
	(void)sig_num;
	write(2,"quit\n", 5);
	//signal(SIGINT, sigint_handle);
	set_msh_signals();
}
