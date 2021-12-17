/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:02:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/17 22:04:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	Return the function pointer to the builtin named in the string.
**	NULL if none.
*/

t_builtin_funcp	get_builtin(char *str)
{
	if (str == NULL)
		return (NULL);
	else if (ft_strcmp(str, "exit") == 0)
		return (builtins_exit);
	else if (ft_strcmp(str, "env") == 0)
		return (builtins_env);
	else if (ft_strcmp(str, "pwd") == 0)
		return (builtins_pwd);
	//else if (ft_strcmp(str, "echo") == 0) TODO, lol
	//	return (builtins_echo);
	else if (ft_strcmp(str, "cd") == 0)
		return (builtins_cd);
	//else if (ft_strcmp(str, "export") == 0) TODO, BTW
	//	return (builtins_export);
	else if (ft_strcmp(str, "unset") == 0)
		return (builtins_unset);
	return (NULL);
}
