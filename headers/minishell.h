/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:45:27 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/07/31 19:46:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define	MINISHELL_H

typedef enum e_behavior
{
	default,
	redir_in,
	redir_out,
	redir_in_append,
	here_doc,
	dollar_var,
	pipe
}			t_behavior;

typedef struct s_token
{
	struct s_token	*next;
	char			*text;
	t_behavior		behavior;
}			t_token;

#endif
