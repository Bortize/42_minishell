/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:44:47 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/15 13:38:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h> //TODO tmp

void	sigquit_handler(void)
{
	rl_on_new_line();
	rl_redisplay();
	if (0)
		write(2,"lol",3);
}
