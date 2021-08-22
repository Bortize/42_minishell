/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:28:09 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/21 20:17:47 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h> //TODO

void	split_in_cmds(char *line)//, t_cmdlst **cmd_lst)
{
	char	read_mode;
	size_t	cmd_start;
	size_t	i;

	read_mode = 0;
	cmd_start = 0;
	i = 0;
	while (line[i])
	{
		if (read_mode == 0)
		{
			if (line[i] == '\'' || line[i] == '\"')
				read_mode = line[i];
			else if (line[i] == '|')
			{
				tokenize_cmd(ft_strndup(line + cmd_start, i - cmd_start));
				cmd_start = i + 1;
			}
		}
		else if (line[i] == read_mode)
			read_mode = 0;
		i++;
	}
	tokenize_cmd(ft_strndup(line + cmd_start, i - cmd_start));
}
