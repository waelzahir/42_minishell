/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/30 19:26:08 by sel-kham         ###   ########.fr       */
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

void	execute_single_cmd(t_token **token, t_btree *root, int type, int *fd)
{
	char	**cmd;
	char	*path;

	expander(token);
	remember_redi(0);
	if (redirect(get_redirection(token)) == 1)
        exit(127);
	cmd = join_tokens(token);
	if (!cmd)
		return ;
	if (!is_builtin(cmd[0]))
	{
		exit_stat[3] = exec_built(cmd);
		remember_redi(1);
		return ;
	}
	else
		executor(root, type, fd);
	remember_redi(1);
}

void	shell(char *prompt)
{
	t_btree	*root;
	char	*line;
	int		fd[2];

	signals_handler();
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
				{
					if (root->num == CMD)
						execute_single_cmd(root->content, root, ROOT, fd);
					else
						executor(root, ROOT, fd);
				}
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
