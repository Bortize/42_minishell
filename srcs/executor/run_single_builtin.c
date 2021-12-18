/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:35:59 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/18 19:03:52 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	restore_io(int stdin_cpy, int stdout_cpy)
{
	if (dup2(stdin_cpy, STDIN_FILENO) == -1
			|| dup2(stdout_cpy, STDOUT_FILENO) == -1)
		perror_and_exit("DUP2:", errno);
}

void	run_single_builtin(t_builtin_funcp builtin, t_cmd *cmd,
			t_list **env_lst)
{
	int	builtin_ret;
	int	stdin_cpy;
	int	stdout_cpy;

	stdin_cpy = dup(STDIN_FILENO);
	stdout_cpy = dup(STDOUT_FILENO);
	if (stdin_cpy == -1 || stdout_cpy == -1)
		perror_and_exit("DUP:", errno);
	if (redirect_input(cmd->lst_redir_in, cmd->heredoc_filename) == -1
			|| redirect_output(cmd->lst_redir_out) == -1)
	{
		restore_io(stdin_cpy, stdout_cpy);
		set_exit_status(1);
		return ;
	}
	builtin_ret = builtin(cmd->argv, env_lst);
	set_exit_status((unsigned char)builtin_ret);
	restore_io(stdin_cpy, stdout_cpy);
	close(stdin_cpy);
	close(stdout_cpy);
}
