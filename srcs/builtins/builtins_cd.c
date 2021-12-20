/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/20 21:08:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Controls the behavior when you want to place the prompt in the
** 'HOME' and it does not exist or is not valid.
*/

static int	home(t_list **env_lst, char *pwd)
{
	char	*home_path;

	home_path = get_current_path(*env_lst, "HOME");
	if (!home_path)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		free(pwd);
		return (1);
	}
	if (chdir(home_path) == -1)
	{
		perror("cd");
		free(pwd);
		return (1);
	}
	env_var_add(env_lst, ft_strdup("OLDPWD"), pwd);
	env_var_add(env_lst, ft_strdup("PWD"), ft_strdup(home_path));
	return (0);
}

/*
** Moves the prompt one level up
*/

static int	go_up(t_list **env_lst, char *pwd)
{
	char	*new_pwd;

	if (chdir("..") != 0)
	{
		perror("cd");
		free(pwd);
		return (1);
	}
	new_pwd = getcwd(NULL, 4096);
	env_var_add(env_lst, ft_strdup("OLDPWD"), pwd);
	env_var_add(env_lst, ft_strdup("PWD"), new_pwd);
	return (0);
}

/*
** Returns the prompt to the place it came from
*/

static int	back(t_list **env_lst, char *pwd)
{
	char	*new_pwd;

	new_pwd = ft_strdup(get_current_path(*env_lst, "OLDPWD"));
	if (chdir(new_pwd) != 0)
	{
		perror("cd");
		free(new_pwd);
		return (1);
	}
	env_var_add(env_lst, ft_strdup("OLDPWD"), pwd);
	env_var_add(env_lst, ft_strdup("PWD"), new_pwd);
	return (0);
}

/*
** Moves to the directory passed as argument
*/

static int	cd(t_list **env_lst, char *pwd, char *aux)
{
	char	*new_pwd;

	if (chdir(aux) != 0)
	{
		perror("cd");
		free(pwd);
		return (1);
	}
	new_pwd = getcwd(NULL, 4096);
	env_var_add(env_lst, ft_strdup("OLDPWD"), pwd);
	env_var_add(env_lst, ft_strdup("PWD"), new_pwd);
	return (0);
}

/*
** Moves the prompt between directory levels
*/

int	builtins_cd(char **argv, t_list **env_lst)
{
	char	*pwd;

	pwd = getcwd(NULL, 4096);
	if ((argv[1] == NULL)
		|| (ft_strcmp(argv[0], "cd") == 0 && ft_strcmp(argv[1], "--") == 0))
		return (home(env_lst, pwd));
	else if (ft_strcmp(argv[1], "..") == 0)
		return (go_up(env_lst, pwd));
	else if (ft_strcmp(argv[1], "-") == 0)
		return (back(env_lst, pwd));
	else
		return (cd(env_lst, pwd, argv[1]));
	return (42);
}
