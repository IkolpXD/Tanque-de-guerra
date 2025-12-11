/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:51:31 by made-jes          #+#    #+#             */
/*   Updated: 2025/12/11 16:51:31 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*split_and_create_tokens(char *expanded)
{
	char	**parts;
	int		i;
	t_token	*list;
	t_token	*node;

	if (!expanded)
		return (NULL);
	parts = ft_split(expanded, ' ');
	if (!parts)
		return (NULL);
	list = NULL;
	i = 0;
	while (parts[i])
	{
		if (parts[i][0] != '\0')
		{
			node = new_token(parts[i]);
			append_token_list(&list, node);
		}
		free(parts[i]);
		i++;
	}
	free(parts);
	return (list);
}

static int	handle_quotes(char *quote, char c)
{
	if (!*quote && (c == '\'' || c == '"'))
	{
		*quote = c;
		return (1);
	}
	if (*quote && c == *quote)
	{
		quote = 0;
		return (1);
	}
	return (0);
}

static char	*expand_or_append(char *res, char *str, int *i, char quote)
{
	if (str[*i] == '$' && quote != '\'')
	{
		(*i)++;
		return (expand_var(res, str, i));
	}
	return (ft_strjoin_char_free(res, str[(*i)++]));
}

char	*expand_token_value(char *str)
{
	char	*res;
	int		i;
	char	quote;

	if (!str)
		return (ft_strdup(""));
	res = ft_strdup("");
	i = 0;
	quote = 0;
	while (str && str[i])
	{
		if (handle_quotes(&quote, str[i]))
		{
			i++;
			continue ;
		}
		res = expand_or_append(res, str, &i, quote);
	}
	return (res);
}
