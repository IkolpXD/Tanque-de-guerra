/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:06:41 by made-jes          #+#    #+#             */
/*   Updated: 2025/12/11 23:06:41 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(char **envp)
{
	t_shell	*sh;

	sh = get_shell();
	init_env(envp);
	sh->last_exit = 0;
}

void	add_env_var(char *entry)
{
	t_env	*node;
	char	*eq;

	node = malloc(sizeof(t_env));
	eq = ft_strchr(entry, '=');
	node->key = ft_substr(entry, 0, eq - entry);
	node->value = ft_strdup(eq + 1);
	node->next = get_shell()->env;
	get_shell()->env = node;
}

void	init_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		add_env_var(envp[i]);
		i++;
	}
}
