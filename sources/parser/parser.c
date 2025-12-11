/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:00:48 by made-jes          #+#    #+#             */
/*   Updated: 2025/11/30 17:38:48 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	syntax_error(char *token)
{
	printf("minishell: syntax error near unexpected token %s\n", token);
	return (1);
}

int	validate_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			if (!prev || prev->type == PIPE)
				return (syntax_error("|"));
			if (!tokens->next || tokens->next->type == PIPE)
				return (syntax_error("|"));
		}
		if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
			|| tokens->type == APPEND || tokens->type == HEREDOC)
		{
			if (!tokens->next || (tokens->next->type != WORD
					&& tokens->next->type != STR))
				return (syntax_error(tokens->value));
		}
		prev = tokens;
		tokens = tokens->next;
	}
	return (0);
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens)
	{
		if (tokens->type == WORD || tokens->type == STR)
			count++;
		else if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
			|| tokens->type == APPEND || tokens->type == HEREDOC)
			tokens = tokens->next;
		tokens = tokens->next;
	}
	return (count);
}

void	fill_args(t_ast *node, t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (tokens->type == WORD || tokens->type == STR)
			node->cmd_args[i++] = ft_strdup(tokens->value);
		else if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
			|| tokens->type == APPEND || tokens->type == HEREDOC)
			tokens = tokens->next;
		tokens = tokens->next;
	}
	node->cmd_args[i] = NULL;
}

void	add_redir(t_ast *node, int type, char *filename)
{
	t_redir	*redir;
	t_redir	*current;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return ;
	redir->type = type;
	redir->filename = ft_strdup(filename);
	redir->next = NULL;
	if (!node->redirs)
		node->redirs = redir;
	else
	{
		current = node->redirs;
		while (current->next)
			current = current->next;
		current->next = redir;
	}
}
