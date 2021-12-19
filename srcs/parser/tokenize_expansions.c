/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:40:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/19 18:20:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define SINGLEQ 0b01
#define DOUBLEQ 0b10

#define TOKEN_VAR_COND 0
#define TOKEN_TEXT_COND 1

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
	char			*var_key;
	char			*var_val;
	const size_t	var_len = read_variable(str + 1);

	if (var_len == 0)
		return (ft_strdup("$"));
	var_key = ft_substr(str + 1, 0, var_len);
	if (!var_key)
		return (NULL);
	var_val = get_current_path(env, var_key);
	free(var_key);
	if (!var_val)
		return (ft_strdup(""));
	if (*(str + 1) == '?')
		return (var_val);
	return (ft_strdup(var_val));
}

static void	add_tk(t_list **tk_lst, char *str)
{
	t_list	*aux_node;

	aux_node = ft_lstnew(str);
	if (!aux_node || !str)
		perror_and_exit("Fatal:", errno);
	ft_lstadd_back(tk_lst, aux_node);
}

//NORM forced me to do this.
static void	update_iterator(char **line_ref, char **begin_ref, int condition)
{
	if (condition == TOKEN_TEXT_COND)
	{
		if (**line_ref && **line_ref != '$')
			(*line_ref)++;
		*begin_ref = *line_ref;
	}
	else if (condition == TOKEN_VAR_COND)
	{
		(*line_ref)++;
		*line_ref += read_variable(*line_ref);
		*begin_ref = *line_ref;
	}
}

//A valid line is assumed to be had. The quotes correctly closed.
void	tokenize_expansions(t_list **tk_lst, char *line, t_list *env)
{
	char	*substr_bgn;
	char	status;

	status = 0;
	substr_bgn = line;
	while (*substr_bgn)
	{
		update_status(&status, *line);
		if (*line == '$' && !(status & SINGLEQ) && line == substr_bgn)
		{
			add_tk(tk_lst, get_var_str(env, substr_bgn));
			update_iterator(&line, &substr_bgn, TOKEN_VAR_COND);
		}
		else if (!*line || (*line == '$' && !(status & SINGLEQ))
			|| (!(status & SINGLEQ) && *line == '\"')
			|| (!(status & DOUBLEQ) && *line == '\''))
		{
			add_tk(tk_lst, ft_strndup(substr_bgn, line - substr_bgn));
			update_iterator(&line, &substr_bgn, TOKEN_TEXT_COND);
		}
		else
			++line;
	}
}
