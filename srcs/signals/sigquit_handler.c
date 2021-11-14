/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:44:47 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/14 18:48:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> //TODO maybe just make iot smaller
#include <unistd.h> //TODO tmp

void	sigquit_handler(void)
{
	if (0)
		write(2,"lol",3);
}
