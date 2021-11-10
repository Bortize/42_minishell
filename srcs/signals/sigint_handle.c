/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:10 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/10 16:01:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp
void	sigint_handle(int sig_num)
{
	(void)sig_num;
	write(2,"intr\n", 5);
	//signal(SIGQUIT, sigquit_handle);
	set_msh_signals();
}
