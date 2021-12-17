/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:25:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/17 22:09:58 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	builtins_env(char **argv, t_list **env_lst)
{
	(void)argv;
	ft_lstiter(*env_lst, print_env);
	return (0);
}
