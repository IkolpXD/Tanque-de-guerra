/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:51:15 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/28 21:51:15 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*find_last_pipe(t_token *tokens)
{
	t_token	*last_pipe;

	last_pipe = NULL;
	while (tokens && tokens->next)
	{
		if (tokens->type == PIPE)
			last_pipe = tokens;
		tokens = tokens->next;
	}
	return (last_pipe);
}

static void	parse_redirections(t_ast *node, t_token *tokens)
{
	while (tokens)
	{
		if ((tokens->type == REDIR_IN || tokens->type == REDIR_OUT
				|| tokens->type == APPEND || tokens->type == HEREDOC)
			&& tokens->next)
		{
			add_redir(node, tokens->type, tokens->next->value);
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
}

static t_ast	*parse_command_and_redirs(t_token *tokens)
{
	t_ast	*node;
	int		count;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = NODE_CMD;
	node->left = NULL;
	node->right = NULL;
	node->redirs = NULL;
	count = count_args(tokens);
	node->cmd_args = malloc(sizeof(char *) * (count + 1));
	if (!node->cmd_args)
	{
		free(node);
		return (NULL);
	}
	fill_args(node, tokens);
	parse_redirections(node, tokens);
	return (node);
}

t_ast	*build_ast(t_token *tokens)
{
	t_token	*pipe;
	t_token	*left_tokens;
	t_token	*right_tokens;
	t_ast	*node;

	if (!tokens)
		return (NULL);
	pipe = find_last_pipe(tokens);
	if (pipe)
	{
		left_tokens = tokens;
		right_tokens = pipe->next;
		pipe->next = NULL;
		node = malloc(sizeof(t_ast));
		if (!node)
			return (NULL);
		node->type = NODE_PIPE;
		node->left = build_ast(left_tokens);
		node->right = build_ast(right_tokens);
		return (node);
	}
	else
		return (parse_command_and_redirs(tokens));
}
