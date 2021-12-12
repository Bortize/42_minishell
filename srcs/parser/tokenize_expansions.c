/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:40:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/12 21:56:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define SINGLEQ 0b01
#define DOUBLEQ 0b10

//Called after reading a non-escaped quote or $.
static void	update_status(char *status, char ch_read)
{
	char	flag;

	flag = *status;
	if (ch_read == '\'' && !(flag & DOUBLEQ))
	{
		if (flag & SINGLEQ)
			flag &= ~SINGLEQ;
		else
			flag |= SINGLEQ;
	}
	else if (ch_read == '\"' && !(flag & SINGLEQ))
	{
		if (flag & DOUBLEQ)
			flag &= ~DOUBLEQ;
		else
			flag |= DOUBLEQ;
	}
	*status = flag;
}

static char	*get_var_str(t_list *env, char *str)
{
	t_env_var	*var_node;
	char		*var_key;

	var_key = ft_substr(str + 1, 0, read_variable(str + 1));//
			ft_putstr_fd("var:", 2);
			ft_putstr_fd(var_key, 2);
			ft_putstr_fd("\n", 2);
	if (!var_key)
		return (NULL);
	var_node = env_var_find(env, var_key);
	free(var_key);
	dprintf(2, "val %p\n", var_node);
	if (!var_node || !var_node->value)
		return (ft_strdup(""));
	return (ft_strdup(var_node->value));
}

static t_list	*add_tk_cln_fail(t_list **tk_lst, char *str)
{
	t_list	*aux_node;

	aux_node = ft_lstnew(str);
	if (!aux_node || !str)
	{
		perror("Memory unavailable.");
		free(str);
		free(aux_node);
		ft_lstclear(tk_lst, free);
		*tk_lst = NULL;
		return (NULL);
	}
	ft_lstadd_back(tk_lst, aux_node);
	return (*tk_lst);
}

//A valid line is assumed to be had. The quotes correctly closed.
t_list	*tokenize_expansions(char *line, t_list *env)
{
	t_list	*tk_lst;
	char	*substr_bgn;
	char	status;

	tk_lst = NULL;
	status = 0;
	substr_bgn = line;
	while (*substr_bgn)
	{
		update_status(&status, *line);
		if (*line == '$' && !(status & SINGLEQ) && line == substr_bgn)
		{
			line++;
			line += read_variable(line);
			if (!add_tk_cln_fail(&tk_lst, get_var_str(env, substr_bgn)))
				return (NULL);
			substr_bgn = line;
		}
		else if (!*line || (*line == '$' && !(status & SINGLEQ))
				|| (~(status & SINGLEQ) && *line == '\"')
				|| (~(status & DOUBLEQ) && *line == '\''))
		{
			if (!add_tk_cln_fail(&tk_lst, ft_strndup(substr_bgn, line - substr_bgn)))
				return (NULL);
			if (*line != '$')
				line++;
			substr_bgn = line;
		}
		else
			++line;
	}
	return (tk_lst);
}
