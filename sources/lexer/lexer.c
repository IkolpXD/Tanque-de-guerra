/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:47:37 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/15 19:35:30 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*lexer(char *line)
{
	char	**result;
	t_token	*token_list;

	if (!line)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if (!result)
		return (NULL);
	fill_tokens(result, line);
	token_list = create_list(result);
	free_split(result);
	get_shell()->tokens = token_list;
	return (token_list);
}

t_token_type	get_token_type(char *line)
{
	if (!line)
		return (UNKNOWN);
	if (ft_strncmp(line, "|", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(line, "<<", 3) == 0)
		return (HEREDOC);
	else if (ft_strncmp(line, ">>", 3) == 0)
		return (APPEND);
	else if (ft_strncmp(line, "<", 2) == 0)
		return (REDIR_IN);
	else if (ft_strncmp(line, ">", 2) == 0)
		return (REDIR_OUT);
	else if ((line[0] == '"' && line[ft_strlen(line) - 1] == '"')
		|| (line[0] == '\'' && line[ft_strlen(line) - 1] == '\''))
		return (STR);
	else
		return (WORD);
}

t_token	*new_token(char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = get_token_type(value);
	token->next = NULL;
	return (token);
}

t_token	*create_list(char **result)
{
	t_token	*head;
	t_token	*tail;
	t_token	*new;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (result[i])
	{
		new = new_token(result[i]);
		if (!new)
			return (NULL);
		if (!head)
			head = new;
		else
			tail->next = new;
		tail = new;
		i++;
	}
	return (head);
}
