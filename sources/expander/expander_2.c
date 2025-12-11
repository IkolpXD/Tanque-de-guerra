/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:22:28 by made-jes          #+#    #+#             */
/*   Updated: 2025/11/30 16:22:28 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	var_len(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i);
}

static char	*expand_exit_status(void)
{
	return (ft_itoa(get_shell()->last_exit));
}

char	*expand_var(char *res, char *str, int *i)
{
	char	*key;
	char	*val;
	int		len;

	if (str[*i] == '?')
	{
		val = expand_exit_status();
		res = ft_strjoin_free(res, val);
		free(val);
		(*i)++;
		return (res);
	}
	len = var_len(&str[*i]);
	if (len == 0)
		return (ft_strjoin_char_free(res, '$'));
	key = ft_substr(str, *i, len);
	val = get_env_value(key);
	if (val)
		res = ft_strjoin_free(res, val);
	free(key);
	*i += len;
	return (res);
}

char	*expand_dollar(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (ft_strdup(""));
	res = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			res = expand_var(res, str, &i);
		}
		else
			res = ft_strjoin_char_free(res, str[i++]);
	}
	return (res);
}

void	append_token_list(t_token **head, t_token *new_node)
{
	t_token	*current;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
