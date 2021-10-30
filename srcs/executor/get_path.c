/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:29:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/10/31 00:01:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <unistd.h>

static int	check_path(char *path)
{
	struct stat	info;

	if (!path || stat(path, &info) == -1)
		return (-1);
	if ((info.st_mode & S_IFREG) == 0)
		return (-1);
	return (0);
}

//TODO I'm adding this to the libft.
static void	ft_free_arr(void **ptr_arr)
{
	int	i;

	i = 0;
	while (ptr_arr[i])
	{
		free(ptr_arr[i]);
		i++;
	}
	free(ptr_arr);
}

//TODO Maybe check before anything else? for paths like ./a.out or ../a.out
char	*get_path(char *file, char *path_env)
{
	char	**pathv;
	char	**path_iter;
	char	*full_path;
	char	*slash_file;

	//Memory management should be done better.
	slash_file = ft_strjoin("/", file);
	if (!slash_file)
		return (NULL);
	pathv = ft_split(path_env, ':');
	path_iter = pathv;
	if (!pathv)
	{
		free(slash_file);
		return (NULL);
	}
	full_path = NULL;
	while (!full_path && *path_iter)
	{
		full_path = ft_strjoin(*path_iter, slash_file);
		write(2, full_path, ft_strlen(full_path));
		if (check_path(full_path) != 0)
		{
			free(full_path);
			full_path = NULL;
		}
		path_iter++;
	}
	ft_free_arr((void **)pathv);
	return (full_path);
}
