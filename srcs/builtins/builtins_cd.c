/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/11/20 17:04:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtins_cd(char **arg, t_list *env_lst)
{
	(void) (arg);
	(void) (env_lst);

	printf("NO TE OLVIDES DE MI");
/*:	char *pwd;
	char buff[PATH_MAX];
	int i;

	i = 0;
	while(arg[i])
	{
		i++;
		if (i == 3)
			return ;
	}
	pwd = getcwd(buff, 4096);
	if (!arg || (ft_strcmp(arg, "--") == 0))
	{
		chdir( Devolver al HOME );
		return 0;
	}
	else if (ft_strcmp(arg, "-"))
	{
		chdir( Devolver al prompt anterior  );
	}
	else if (arg[2])
	{
		chdir(: Devolver ERROR );
	}
	else
	{
		chdir(arg);
	}
*/
}