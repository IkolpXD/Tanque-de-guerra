/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:59:14 by made-jes          #+#    #+#             */
/*   Updated: 2025/11/30 17:59:14 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	handle_sigquit(int sig)
{
	(void)sig;
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

static void	update_env(t_env *env)
{
	int		current_lvl;
	char	*new_value;

	while (env)
	{
		if (ft_strncmp(env->key, "SHLVL", 6) == 0)
		{
			current_lvl = ft_atoi(env->value);
			current_lvl++;
			new_value = ft_itoa(current_lvl);
			free(env->value);
			env->value = new_value;
			return ;
		}
		env = env->next;
	}
}

void	handle_builtin(char *line)
{
	if (ft_strncmp(line, "clear", 6) == 0)
	{
		rl_clear_history();
		write(1, "\033[H\033[J", 6);
	}
	else if (ft_strncmp(line, "exit", 5) == 0)
	{
		rl_clear_history();
		exit(get_shell()->last_exit);
	}
	else if (ft_strncmp(line, "bash", 5) == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		update_env(get_shell()->env);
	}
	else
		add_history(line);
}
