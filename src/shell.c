/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/06 23:49:37 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	get_ret_val(void)
{
	if (WIFEXITED(g_exit_stat[0]))
		return (WEXITSTATUS(g_exit_stat[0]));
	return (0);
}

void	waiting(void)
{
	int	j;

	j = 0;
	while (wait(NULL) > 0)
		;
	rl_catch_signals = 0;
	signals_handler();
	if (g_exit_stat[0] == -99)
		return ;
	if (WIFSIGNALED(g_exit_stat[0]))
	{
		j = WTERMSIG(g_exit_stat[0]);
		if (j > 2)
		{
			ft_putstr_fd("Quit: ", 1);
			ft_putnbr_fd(j, 1);
		}
		g_exit_stat[3] = 128 + WTERMSIG(g_exit_stat[0]);
		ft_putstr_fd("\n", 1);
		return ;
	}
	if (WIFEXITED(g_exit_stat[0]))
		g_exit_stat[3] = WEXITSTATUS(g_exit_stat[0]);
}

void	remember_redi(int i)
{
	if (i == 0)
	{
		g_exit_stat[1] = dup(0);
		g_exit_stat[2] = dup(1);
	}
	else if (i == 1)
	{
		dup2(g_exit_stat[1], 0);
		dup2(g_exit_stat[2], 1);
	}
}

void	shell(char *prompt)
{
	char		*line;
	extern char	**environ;
	int			fd[2];

	rl_catch_signals = 0;
	signals_handler();
	while (1)
	{
		if (!*environ)
			add_env_var("\0", NULL);
		line = readline(prompt);
		if (line && line[0] != '\0')
		{
			add_history(line);
			shell_routine(line, fd);
			free(line);
		}
		else if (!line)
			break ;
	}
}

void	shell_routine(char	*line, int *fd)
{
	t_btree	*root;

	root = NULL;
	if (closing_check(line, fd) == 0)
	{
		root = parser(line);
		binary_tree_new(NULL, 0, 1, NULL);
		if (root)
			exe_launcher(root, ROOT, fd);
		waiting();
		binary_tree_free(&root);
	}
}
