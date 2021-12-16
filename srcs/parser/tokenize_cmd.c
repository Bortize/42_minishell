/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:04:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/12/16 20:37:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*create_redirect_node(char *redir_name, t_behavior redir_type)
{
	t_redirect	*new_redir;
	t_list		*redir_node;

	new_redir = ft_calloc(1, sizeof(t_redirect));
	redir_node = ft_lstnew(new_redir);
	if (!new_redir || !redir_node)
		exit(1);
	new_redir->text = redir_name;
	new_redir->type = redir_type;
	return (redir_node);
}

static int	read_token_behavior(char *line, t_behavior *type)
{
	*type = plain;
	if (line[0] == '>')
	{
		if (line[1] == '>')
		{
			*type = redir_out_append;
			return (2);
		}
		*type = redir_out;
		return (1);
	}
	else if (line[0] == '<')
	{
		if (line[1] == '<')
		{
			*type = here_doc;
			return (2);
		}
		*type = redir_in;
		return (1);
	}
	return (0);
}

static void	save_token(t_cmd *cmd_node, char *token, t_behavior token_type,
		t_list *env_lst)
{
	void	*aux;
	char	*expanded_token;

	if (!token)
		exit (1); //TODO Print FATAL no memory and exit;
	expanded_token = expand_str(token, env_lst);
	free(token);
	if (!expanded_token)
		exit (1); //TODO Print FATAL no memory and exit;
	if (token_type == plain)
	{
		aux = ft_lstnew(expanded_token);
		if (!aux)
			exit (1);
		ft_lstadd_back(&cmd_node->arg, aux);
	}
	else
	{
		aux = create_redirect_node(expanded_token, token_type);
		if (token_type == redir_in || token_type == here_doc)
			ft_lstadd_back(&cmd_node->lst_redir_in, aux);
		else
			ft_lstadd_back(&cmd_node->lst_redir_out, aux);
	}
}

void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node, t_list *env_lst)
{
	t_behavior	token_behavior;
	size_t		token_len;

	cmd_txt += count_spaces(cmd_txt);
	if (*cmd_txt == 0)
		return ;
	token_behavior = plain;
	cmd_txt += read_token_behavior(cmd_txt, &token_behavior);
	cmd_txt += count_spaces(cmd_txt);
	token_len = 0;
	while (cmd_txt[token_len] && !is_delimiter(cmd_txt[token_len]))
	{
		if (cmd_txt[token_len] == '\'' || cmd_txt[token_len] == '\"')
			token_len += count_until_repeat(cmd_txt + token_len);
		else
			token_len++;
	}
	save_token(cmd_node, ft_strndup(cmd_txt, token_len), token_behavior,
		env_lst);
	return (tokenize_cmd(cmd_txt + token_len, cmd_node, env_lst));
}
