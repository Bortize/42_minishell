/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:25:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/21 15:45:45 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "minishell.h"
#include <stdlib.h>

#define FUNCTION string_validator

void	free_str_arr(char **str_arr)
{
	char	*i;

	i = *str_arr;
	while (i)
		free(i++);
	free(str_arr);
}

void	test_syntax(int (*f)(char *), char **args)
{
	if (f(args[0]))
	{
		printf("TEST[%s-%s]->", args[0], args[1]);
		if (ft_strcmp("OK", args[1]) == 0)
			printf("SUCCESS\n");
		else
			printf("FAILURE\n");
	}
	else
	{
		printf("TEST[%s-%s]->", args[0], args[1]);
		if (ft_strcmp("OK", args[1]) == 0)
			printf("FAILURE\n");
		else
			printf("SUCCESS\n");
	}
}

int	main(void)
{
	char	*line;
	char	**args;

	while ((line = readline(NULL)) != NULL)
	{
		args = ft_split(line, ';');
		free(line);
		test_syntax(FUNCTION, args);
		free_str_arr(args);
	}
}

