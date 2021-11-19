/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:36:50 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/19 20:50:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/ioctl.h>
#include <unistd.h>

static void	sigint_handler(void)
{
	if (g_pidv[0] != 0) //Dirty way to know we are in iteractive move TODO
		return ;
	g_interrupted = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
}

static void	sigquit_handler(void)
{
	if (g_pidv[0] != 0) //Dirty way to know we are in iteractive move TODO
		return ;
	rl_on_new_line();
	rl_redisplay();
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		sigint_handler();
	else if (signum == SIGQUIT)
		sigquit_handler();
}
