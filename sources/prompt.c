/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:33:21 by made-jes          #+#    #+#             */
/*   Updated: 2026/02/03 18:31:04 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	freeing_stuff(char *line, t_token *tokens)
{
	//print_ast(get_shell()->ast, 0);
	free_ast(get_shell()->ast);
	get_shell()->ast = NULL;
	free_token_list(tokens);
	free(line);
}

/*static void	print_token_list(t_token *tokens)
{
	while (tokens)
	{
		printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
}*/

void	run_prompt(void)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		handle_builtin(line);
		tokens = lexer(line);
		//printf("%s", "Before expansion:\n");
		//print_token_list(tokens);
		expand_tokens(&tokens);
		if (validate_syntax(tokens))
		{
			free_token_list(tokens);
			free(line);
			continue ;
		}
		//printf("%s", "After expansion:\n");
		//print_token_list(tokens);
		get_shell()->ast = build_ast(tokens);
		//printf("%s", "the problem is here:\n");
		freeing_stuff(line, tokens);
	}
}
