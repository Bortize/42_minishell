/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:37:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/03 18:40:36 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "readline/readline.h"
#include "readline/history.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	size_t	i;
	size_t	var_size;

	while (1)
	{
		i = 0;
		line = readline("Write your variable here.");
		while (line[i])
		{
			if (line[i] == '$')
			{
				i++;
				var_size = read_variable(&line[i]);
				printf("VAR:%*.*s\n", (int)var_size, (int)var_size, line + i);
				i += var_size;
			}
			else
				i++;
		}
		free(line);
	}
	return (0);
}
