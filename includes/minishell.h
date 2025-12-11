/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:50:01 by made-jes          #+#    #+#             */
/*   Updated: 2025/12/11 23:10:34 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_token_type
{
	WORD,
	STR,
	PIPE,
	REDIR_IN, // <
	REDIR_OUT, // >
	APPEND, // >>
	HEREDOC, // <<
	UNKNOWN
}				t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

typedef enum e_node_type
{
	NODE_CMD,
	NODE_PIPE,
	NODE_REDIR
}			t_node_type;

typedef struct s_redir
{
	int				type;
	char			*filename;
	struct s_redir	*next;
}				t_redir;

typedef struct s_ast
{
	t_node_type		type;
	char			**cmd_args;
	t_redir			*redirs;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_token		*tokens;
	t_ast		*ast;
	t_env		*env;
	int			last_exit;
}				t_shell;

t_shell			*get_shell(void);
void			init_shell(char **envp);
void			run_prompt(void);

//Lexer
t_token			*lexer(char *line);
t_token			*new_token(char *value);
t_token			*create_list(char **result);
void			fill_tokens(char **result, const char *line);
t_token_type	get_token_type(char *line);

//Parsing
int				validate_syntax(t_token *tokens);
t_ast			*build_ast(t_token *tokens);
t_token			*find_last_pipe(t_token *tokens);
int				count_args(t_token *tokens);
void			fill_args(t_ast *node, t_token *tokens);
void			add_redir(t_ast *node, int type, char *filename);
void			print_ast(t_ast *node, int depth);

//Expander
void			add_env_var(char *entry);
void			init_env(char **envp);
char			*get_env_value(char *key);
char			*expand_var(char *res, char *str, int *i);
void			expand_tokens(t_token **tokens);
void			append_token_list(t_token **head, t_token *new_node);
t_token			*split_and_create_tokens(char *expanded);
char			*expand_token_value(char *str);
void			print_env(void);

//Signals and commands to exit
void			setup_signals(void);
void			handle_builtin(char *line);

//Freeing
void			free_split(char **arr);
void			free_token_list(t_token *tokens);
void			free_redirs(t_redir *redir);
void			free_ast(t_ast *node);
void			free_env_list(t_env *env);

#endif
