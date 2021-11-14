/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:36:50 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/14 18:43:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		sigint_handler();
	else if (signum == SIGQUIT)
		sigquit_handler();
}
