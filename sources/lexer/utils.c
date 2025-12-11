/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:03:42 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/14 22:03:42 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*handle_quotes(const char *line, int *i)
{
	int		start;
	char	quote;

	start = *i;
	quote = line[(*i)];
	(*i)++;
	while (line[*i])
	{
		if (line[*i] == '\\' && quote == '"' && line[*i + 1])
		{
			*i += 2;
			continue ;
		}
		if (line[*i] == quote)
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	return (ft_substr(line, start, *i - start));
}

static char	*handle_double_operator(const char *line, int *i)
{
	char	*op;

	op = ft_substr(line, *i, 2);
	*i += 2;
	return (op);
}

static char	*handle_single_operator(const char *line, int *i)
{
	char	*op;

	op = ft_substr(line, (*i)++, 1);
	return (op);
}

static char	*handle_word(const char *line, int *i)
{
	int	start;

	start = *i;
	while (line[*i] && !ft_is_space(line[*i]) && line[*i] != '>'
		&& line[*i] != '<' && line[*i] != '|' && line[*i] != '\''
		&& line[*i] != '\"')
		(*i)++;
	return (ft_substr(line, start, *i - start));
}

void	fill_tokens(char **result, const char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (ft_is_space(line[i]))
			i++;
		if (line[i] == '\0')
			break ;
		if (line[i] == '\'' || line[i] == '\"')
			result[j++] = handle_quotes(line, &i);
		else if ((line[i] == '>' && line[i + 1] == '>')
			|| (line[i] == '<' && line[i + 1] == '<'))
			result[j++] = handle_double_operator(line, &i);
		else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			result[j++] = handle_single_operator(line, &i);
		else
			result[j++] = handle_word(line, &i);
	}
	result[j] = NULL;
}
