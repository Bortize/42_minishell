/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:29:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/15 19:02:41 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <unistd.h>

//File exists and -is- a regular file. False if NULL.
static int	valid_file(char *path)
{
	struct stat	info;

	return (!(stat(path, &info) == -1 || (info.st_mode & S_IFREG) == 0));
}

//Absolute paths use '/', or '.' as current dir and '..' as the parent dir.
//Syscalls have no issue accessing any absolute path.
static int	is_absolute(char *path)
{
	return (!path || ft_strncmp(path, "/", 1) == 0
		|| ft_strncmp(path, "./", 2) == 0
		|| ft_strncmp(path, "../", 3) == 0);
}

//Memory management done in the side corner, hidden from the public eye.
//Return is just error-checking.
static void	*set_memory(char ***pathv, char *path_env)
{
	if (!path_env)
		return (NULL);
	*pathv = ft_split(path_env, ':');
	if (!*pathv)
	{
		perror("MINISHELL:");
		return (NULL);
	}
	return (pathv);
}

//Build a path, usually it needs a slash '/' between elements.
static char	*path_add(char *prefix, char *suffix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	const size_t	suffix_len = ft_strlen(suffix);
	char			*path;

	path = malloc(prefix_len + suffix_len + 2);
	if (!path)
		return (path);
	ft_strcpy(path, prefix);
	path[prefix_len] = '/';
	ft_strcpy(path + prefix_len + 1, suffix);
	path[prefix_len + suffix_len + 1] = '\0';
	return (path);
}

//Find the file using the PATH environment as prefix (like sh).
char	*get_path(char *file, char *path_env)
{
	char	**pathv;
	char	**path_iter;
	char	*full_path;

	if (!file || is_absolute(file))
		return (file);
	if (!set_memory(&pathv, path_env))
		return (NULL);
	path_iter = pathv;
	full_path = NULL;
	while (*path_iter)
	{
		full_path = path_add(*path_iter, file);
		if (valid_file(full_path))
			break ;
		free(full_path);
		path_iter++;
	}
	if (*path_iter == NULL)
		return (NULL);
	ft_free_arr((void **)pathv);
	return (full_path);
}
