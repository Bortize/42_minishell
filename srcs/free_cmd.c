/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 01:35:02 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/19 15:55:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(void *elem)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)elem;
	ft_lstclear(&cmd->arg, free);
	ft_lstclear(&cmd->lst_redir_in, free_redirect);
	ft_lstclear(&cmd->lst_redir_out, free_redirect);
	free(cmd);
}
