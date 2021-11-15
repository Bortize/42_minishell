/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:10 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/15 13:26:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "readline/readline.h"
#include <sys/ioctl.h>
#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp

void	rl_replace_line(const char *str, int clear);

void	sigint_handler(void)
{
	g_interrupted = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "minishell> ", 11);
	rl_replace_line("", 123);
	rl_already_prompted = 42;
	rl_on_new_line();
	//rl_redisplay();
}
