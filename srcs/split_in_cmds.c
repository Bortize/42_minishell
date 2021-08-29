/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:28:09 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/29 04:15:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	allocate_new_cmd_in_lst(t_list **cmd_lst)
{
	t_cmd	*new_cmd;
	t_list	*cmd_lst_node;

	new_cmd = ft_calloc(1, sizeof(t_cmd));
	cmd_lst_node = ft_lstnew(new_cmd);
	if (!new_cmd || !cmd_lst_node)
		exit(1); //Exit handler to print errors //TODO NO-MEM
	ft_lstadd_back(cmd_lst, cmd_lst_node);
}

t_list	*split_in_cmds(char *line)
{
	t_list	*cmd_lst;
	char	*tmp;
	size_t	cmd_len;

	cmd_lst = NULL;
	cmd_len = 0;
	while (line[cmd_len])
	{
		if (line[cmd_len] == '\'' || line[cmd_len] == '\"')
			cmd_len += count_until_repeat(line + cmd_len);
		else if (line[cmd_len] == '|' || line[cmd_len + 1] == '\0')
		{
			allocate_new_cmd_in_lst(&cmd_lst);
			tmp = ft_strndup(line, cmd_len);
			tokenize_cmd(tmp, ft_lstlast(cmd_lst)->content);
			free(tmp);
			line += cmd_len;
			cmd_len = 0;
		}
		else
			cmd_len++;
	}
	return (cmd_lst);
}
