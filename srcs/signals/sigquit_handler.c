/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:44:47 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/15 13:27:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "readline/readline.h"
#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp

void	sigquit_handler(void)
{
	rl_on_new_line();
	rl_redisplay();
	if (0)
		write(2,"lol",3);
}
