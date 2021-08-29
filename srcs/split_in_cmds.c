/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:28:09 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/29 21:58:49 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	allocate_new_cmd(t_list **new_cmd)
{
	t_list	*cmd_lst_node;

	*new_cmd = ft_calloc(1, sizeof(t_cmd));
	cmd_lst_node = ft_lstnew(*new_cmd);
	if (!*new_cmd || !cmd_lst_node)
		exit(1); //Exit handler to print errors //TODO NO-MEM
}

//TODO I'm not totally convinced about the way the base case *last_cmd == NULL
//is handled, probably have it the very first thing alongside line being null.
//But that opens a whole can of worms.
void	split_in_cmds(char *line, t_list **last_cmd)
{
	t_list	*new_cmd;
	char	*tmp;
	size_t	cmd_len;

	new_cmd = NULL;
	cmd_len = 0;
	while (line[cmd_len] && line[cmd_len] != '|')
	{
		if (line[cmd_len] == '\'' || line[cmd_len] == '\"')
			cmd_len += count_until_repeat(line + cmd_len);
		else
			cmd_len++;
	}
	allocate_new_cmd(&new_cmd);
	tmp = ft_strndup(line, cmd_len);
	tokenize_cmd(tmp, new_cmd->content);
	free(tmp);
	if (*last_cmd)
		(*last_cmd)->next = new_cmd;
	else
		*last_cmd = new_cmd;
	if (line[cmd_len])
		return (split_in_cmds(line + cmd_len, &new_cmd));
	return ;
}
