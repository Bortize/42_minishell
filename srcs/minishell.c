/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:30:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/08/23 22:13:08 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("hola > ");
		add_history(line);
		split_in_cmds(line);
		free(line);
	}
	return (0);
}
