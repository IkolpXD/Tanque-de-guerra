/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:39:22 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/14 14:39:22 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_indent(int level)
{
	for (int i = 0; i < level; i++)
		printf("    ");
}

static void	print_cmd_args(char **args)
{
	for (int i = 0; args && args[i]; i++)
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
}

void	print_ast(t_ast *node, int level)
{
	t_redir		*redir;
	const char	*type;

	if (!node)
		return ;
	redir = node->redirs;
	print_ast(node->right, level + 1);
	print_indent(level);
	if (node->type == NODE_PIPE)
		printf("[PIPE]\n");
	else if (node->type == NODE_CMD)
	{
		printf("[CMD: ");
		print_cmd_args(node->cmd_args);
		printf("]\n");
		while (redir)
		{
			print_indent(level + 1);
			if (redir->type == REDIR_IN)
				type = "<";
			else if (redir->type == REDIR_OUT)
				type = ">";
			else if (redir->type == APPEND)
				type = ">>";
			else if (redir->type == HEREDOC)
				type = "<<";
			else
				type = "?";
			printf("[REDIR %s %s]\n", type, redir->filename);
			redir = redir->next;
		}
	}
	print_ast(node->left, level + 1);
}

void	print_env(void)
{
	t_env	*env;

	env = get_shell()->env;
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
