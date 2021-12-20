/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 16:44:20 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Controls the behavior when you want to place the prompt in the
** 'HOME' and it does not exist or is not valid.
*/

static int	home(t_list *env_lst, char *pwd)
{
	set_key_value(env_lst, pwd, "OLDPWD");
	free(pwd);
	if (!get_current_path(env_lst, "HOME"))
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(get_current_path(env_lst, "HOME")) == -1)
	{
		perror("cd");
		return (1);
	}
	set_key_value(env_lst, get_current_path(env_lst, "HOME"), "PWD");
	return (0);
}

/*
** Moves the prompt one level up
*/

static int	go_up(t_list *env_lst, char *pwd)
{
	char	*new_pwd;

	set_key_value(env_lst, pwd, "OLDPWD");
	free(pwd);
	if (chdir("..") != 0)
	{
		perror("cd");
		return (1);
	}
	new_pwd = getcwd(NULL, 4096);
	set_key_value(env_lst, new_pwd, "PWD");
	free(new_pwd);
	return (0);
}

/*
** Returns the prompt to the place it came from
*/

static int	back(t_list *env_lst, char *pwd, char *aux)
{
	aux = ft_strdup(get_current_path(env_lst, "OLDPWD"));
	set_key_value(env_lst, pwd, "OLDPWD");
	free(pwd);
	if (chdir(aux) != 0)
	{
		perror("cd");
		free(aux);
		return (1);
	}
	set_key_value(env_lst, aux, "PWD");
	free(aux);
	return (0);
}

/*
** Moves to the directory passed as argument
*/

static int	cd(t_list *env_lst, char *pwd, char *aux)
{
	char	*new_pwd;

	set_key_value(env_lst, pwd, "OLDPWD");
	free(pwd);
	if (chdir(aux) != 0)
	{
		perror("cd");
		return (1);
	}
	new_pwd = getcwd(NULL, 4096);
	set_key_value(env_lst, new_pwd, "PWD");
	free(new_pwd);
	return (0);
}

/*
** Moves the prompt between directory levels
*/

int	builtins_cd(char **argv, t_list **env_lst)
{
	char	*pwd;
	char	*aux;

	aux = NULL;
	pwd = getcwd(NULL, 4096);
	if ((argv[1] == NULL)
		|| (ft_strcmp(argv[0], "cd") == 0 && ft_strcmp(argv[1], "--") == 0))
		return (home(*env_lst, pwd));
	else if (ft_strcmp(argv[1], "..") == 0)
		return (go_up(*env_lst, pwd));
	else if (ft_strcmp(argv[1], "-") == 0)
		return (back(*env_lst, pwd, aux));
	else
		return (cd(*env_lst, pwd, argv[1]));
	return (42);
}
