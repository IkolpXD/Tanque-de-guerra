/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:46:46 by made-jes          #+#    #+#             */
/*   Updated: 2025/11/19 23:46:46 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env_value(char *key)
{
	t_env	*env;

	env = get_shell()->env;
	while (env)
	{
		if (ft_strncmp(env->key, key, ft_strlen(env->key) + 1) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static void	process_token(t_token **new, t_token *current, int split)
{
	char	*exp;
	t_token	*lst;
	t_token	*new_node;

	exp = expand_token_value(current->value);
	if (split)
	{
		lst = split_and_create_tokens(exp);
		if (lst)
			append_token_list(new, lst);
		else
		{
			new_node = new_token(exp);
			new_node->was_quoted = current->was_quoted;
			append_token_list(new, new_node);
		}
	}
	else
	{
		new_node = new_token(exp);
		new_node->was_quoted = current->was_quoted;
		append_token_list(new, new_node);
	}
	free(exp);
}

void	expand_tokens(t_token **tokens)
{
	t_token	*current;
	t_token	*new;

	if (!tokens || !*tokens)
		return ;
	current = *tokens;
	new = NULL;
	while (current)
	{
		if (current->type == WORD)
			process_token(&new, current, 1);
		else if (current->type == STR)
			process_token(&new, current, 0);
		else
			append_token_list(&new, new_token(current->value));
		current = current->next;
	}
	free_token_list(*tokens);
	*tokens = new;
	get_shell()->tokens = new;
}
