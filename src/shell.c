/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/02 22:23:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	closing_check(char *str, int *fd)
{
	int	type;
	int	i;
	int	state;

	type = 0;
	i = 0;
	state = 0;
	fd[0] = -1;
	fd[1] = -1;
	while (str[i])
	{
		if ((str[i] == 39 || str[i] == 34) && state == 0)
		{
			state = 1;
			type = str[i];
			i++;
		}
		if (str[i] == type && state == 1)
			state = 0;
		i++;
	}
	if (state)
		return (printf("error: unclosed quotes\n"), 1);
	return (0);
}
int 	get_ret_val(void)
{
	if (WIFEXITED(exit_stat[0]))
		return (WEXITSTATUS(exit_stat[0]));
	return 0;
}
void	waiting(void)
{

	while (wait(NULL) > 0)
		;
	if (WIFEXITED(exit_stat[0]))
		exit_stat[3] = WEXITSTATUS(exit_stat[0]);
}
void	remember_redi(int i)
{
	if (i == 0)
	{
		exit_stat[1] = dup(0);
		exit_stat[2] = dup(1);
	}
	else if (i == 1)
	{
		dup2(exit_stat[1], 0);
		dup2(exit_stat[2], 1);
	}
}

void	shell(char *prompt)
{
	t_btree	*root;
	char	*line;
	extern char	**environ;
	int		fd[2];

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
			if (closing_check(line, fd) == 0)
			{
				root = parser(line);
				binary_tree_new(NULL, 0, 1);
					if (get_ret_val() == 130)
					{
						exit_stat[0] = 0;
						continue ;
					}
	
				if (root)
					exe_launcher(root, ROOT, fd);
				waiting();
			}
			free(line);
		}
		else if (!line)
		{
			ft_putstr_fd("\b\b  \b\b", 2);
			break ;
		}
	}
}
