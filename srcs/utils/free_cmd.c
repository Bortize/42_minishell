/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 01:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/24 14:12:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>

void	free_cmd(void *elem)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)elem;
	unlink(cmd->heredoc_filename);
	free(cmd->argv);
	free(cmd->heredoc_filename);
	ft_lstclear(&cmd->arg, free);
	ft_lstclear(&cmd->lst_redir_in, free_redirect);
	ft_lstclear(&cmd->lst_redir_out, free_redirect);
	free(cmd);
}
