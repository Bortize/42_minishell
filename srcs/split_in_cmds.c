/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:28:09 by vicmarti          #+#    #+#             */
/*   Updated: 2021/09/20 10:58:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_in_cmds(char *line, t_list **last_cmd)
{
	t_list	*cmd_node;
	t_cmd	*cmd;
	char	*tmp;
	size_t	cmd_len;

	cmd_len = 0;
	while (line[cmd_len] && line[cmd_len] != '|')
	{
		if (line[cmd_len] == '\'' || line[cmd_len] == '\"')
			cmd_len += count_until_repeat(line + cmd_len); 
		else
			cmd_len++;
	}
	tmp = ft_strndup(line, cmd_len);
	cmd = ft_calloc(1, sizeof(t_cmd));
	cmd_node = ft_lstnew(cmd);
	if (!cmd || !cmd_node)
		exit(1); //Exit handler to print errors //TODO NO-MEM
	tokenize_cmd(tmp, cmd);
	ft_lstadd_back(last_cmd, cmd_node);
	free(tmp);
	if (line[cmd_len])
		return (split_in_cmds(line + cmd_len + 1, &(*last_cmd)->next));
}
