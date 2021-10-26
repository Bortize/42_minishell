/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:05:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/10/26 17:06:52 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"

void	builtins(t_list *cmd_lst, char **argv, char **env)
{
	t_cmd *cmd;

	printf("%s\n", cmd->args);

/*
	if argumento == "echo"
		ToDo
	else if argumento == "pwd"
		ToDo
	else if artmento == "env"
		ToDo
*/
}