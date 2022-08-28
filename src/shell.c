/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 22:36:44 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	*closing_check(char *str, int *fd)
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

void	signals(void)
{
	return ;
}

void	waiting(void)
{
	int	stat;

	while (wait(&stat) > 0)
		;
	if (WIFEXITED(stat))
	exit_stat[0] = WEXITSTATUS(stat);
}

void	shell(char *prompt)
{
	t_btree	*root;
	char	*line;
	int		fd[2];

	exit_stat[1] = dup(0);
	exit_stat[2] = dup(1);
	signals();
	while (1)
	{
		line = readline(prompt);
		if (line && line[0] != '\0')
		{
			add_history(line);
			if (closing_check(line, fd) == 0)
			{
				root = parser(line);
				binary_tree_new(NULL, 0, 1);
				if (root)
					executor(root, ROOT, fd);
			}
			free(line);
		}
		else
			break ;
	}
}
