/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:10 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/14 18:50:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp
void	sigint_handler(void)
{
	g_interrupted = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_redisplay();
}
