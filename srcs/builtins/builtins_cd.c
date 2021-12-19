/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:40:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/12/19 19:06:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Counts the number of arguments that are passed
*/

static int	count_arguments(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		i++;
		if (i == 3)
		{
			printf("to many arguments \n");
			return (-1);
		}
	}
	return (i);
}

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

static void	go_up(t_list *env_lst, char *pwd)
{
	char	*new_pwd;

	set_key_value(env_lst, pwd, "OLDPWD");
	if (chdir("..") != 0)
		perror("chdir");
	new_pwd = getcwd(NULL, 4096);
	set_key_value(env_lst, new_pwd, "PWD");
	free(new_pwd);
}

/*
** Returns the prompt to the place it came from
*/

static void	back(t_list *env_lst, char *pwd, char *aux)
{
	aux = ft_strdup(get_current_path(env_lst, "OLDPWD"));
	set_key_value(env_lst, pwd, "OLDPWD");
	if (chdir(aux) != 0)
		perror("cd");
	set_key_value(env_lst, aux, "PWD");
	free(aux);
}

/*
** Moves to the directory passed as argument
*/

static void cd(t_list *env_lst, char *pwd, char *aux)
{
	char *new_pwd;

	set_key_value(env_lst, pwd, "OLDPWD");
	if (chdir(aux) != 0)
		perror("cd");
	new_pwd = getcwd(NULL, 4096);
	set_key_value(env_lst, new_pwd, "PWD");
	free(new_pwd);
}

/*
** Moves the prompt between directory levels
*/

int	builtins_cd(char **argv, t_list **env_lst)
{
	char	*pwd;
	char	*aux;
	int		i;

	i = count_arguments(argv);
	aux = NULL;
	pwd = getcwd(NULL, 4096);
	if ((i == 1)
		|| (ft_strcmp(argv[0], "cd") == 0 && ft_strcmp(argv[1], "--") == 0))
		return (home(*env_lst, pwd));
	else if (ft_strcmp(argv[1], "..") == 0)
		go_up(*env_lst, pwd);
	else if (ft_strcmp(argv[1], "-") == 0)
		back(*env_lst, pwd, aux);
	else if (ft_strcmp(argv[0], "cd") == 0)
		cd(*env_lst, pwd, argv[1]);
	else
	{
		if (chdir(argv[1]) == -1)
			perror("cd");
	}
	free(pwd);
	return (0);
}
