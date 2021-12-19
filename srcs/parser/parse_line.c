/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:42:40 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 19:50:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	build_argvs(t_list *cmd_lst)
{
	t_cmd	*cmd;

	while (cmd_lst)
	{
		cmd = (t_cmd *)cmd_lst->content;
		if (!cmd->arg)
		{
			cmd->argv = NULL;
			return ;
		}
		cmd->argv = build_str_arr(cmd->arg);
		if (!cmd->argv)
			perror_and_exit("FATAL", errno);
		cmd_lst = cmd_lst->next;
	}
}

/*
** Removes spaces from the beginning and end of the collected line
** and returns each word in a token list.
*/

int	parse_line(char *line, t_list **cmd_lst, t_list *env_lst)
{
	char	*trimmed;

	*cmd_lst = NULL;
	trimmed = ft_strtrim(line, " ");
	if (!trimmed || !*trimmed || string_validator(trimmed) == 0)
	{
		free(trimmed);
		return (1);
	}
	split_in_cmds(trimmed, cmd_lst, env_lst);
	free(trimmed);
	build_argvs(*cmd_lst);
	return (0);
}
