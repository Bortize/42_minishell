/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:40:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/12 20:48:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define SINGLEQ 0b001
#define DOUBLEQ 0b010
#define ENV_VAR 0b100

//Called after reading a non-escaped quote or $.
static void	update_status(char *status, char ch_read)
{
	*status &= ~ENV_VAR;
	if (~(*status & SINGLEQ) && ch_read == '$')
		*status |= ENV_VAR;
	else if ((*status & SINGLEQ) && ch_read == '\'')
		*status &= ~SINGLEQ;
	else if ((*status & DOUBLEQ) && ch_read == '\"')
		*status &= ~DOUBLEQ;
	else if (ch_read == '\'')
		*status |= SINGLEQ;
	else
		*status |= DOUBLEQ;
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

static t_list	*add_tk_cln_fail(t_list **tk_lst, char *str,
					size_t len, t_list  *env)
{
	char	*aux_data;
	t_list	*aux_node;

	if (*str == '$')
		aux_data = get_var_str(env, str);
	else
		aux_data = ft_strndup(str, len);
			ft_putstr_fd("in it:", 2);
			ft_putstr_fd(aux_data, 2);
			ft_putstr_fd("\n", 2);
	aux_node = ft_lstnew(aux_data);
	if (!aux_node || !aux_data)
	{
		perror("Memory unavailable.");
		free(aux_data);
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
		if (*line == '$' && ~(status & SINGLEQ) && line == substr_bgn)
		{
			line++;
			line += read_variable(line);
			if (!add_tk_cln_fail(&tk_lst, substr_bgn, line - substr_bgn, env))
				return (NULL);
			substr_bgn = line;
		}
		else if (!*line || (*line == '$' && ~(status & SINGLEQ))
				|| (~(status & SINGLEQ) && *line == '\"')
				|| (~(status & DOUBLEQ) && *line == '\''))
		{
			if (!add_tk_cln_fail(&tk_lst, substr_bgn, line - substr_bgn, env))
				return (NULL);
			update_status(&status, *line);
			if (*line != '$')
				line++;
			substr_bgn = line;
		}
		else
			++line;
	}
	return (tk_lst);
}
