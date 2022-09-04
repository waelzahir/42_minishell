/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:10:29 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/04 20:59:43 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	pipe_helper(int node, int *fd, int in)
{
	if (node != 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
	}
	if (in != -1)
	{
		dup2(in, 0);
		close(in);
	}
}

int	execute(t_token **token, int node, int *fd, int in)
{
	char		**command;
	extern char	**environ;
	char		*path;
	int			pid;

	expander(token);
	pid = ft_fork();
	if (pid == 0)
	{
		pipe_helper(node, fd, in);
		command = join_tokens(token);
		if (!command || redirect(get_redirection(token)) == 1)
			exit(127);
		if (!is_builtin(command[0]))
		{
			g_exit_stat[3] = exec_built(command);
			exit(g_exit_stat[3]);
		}
		path = set_path(command[0]);
		execve(path, command, environ);
		perror("execve");
		exit(127);
	}
	return (return_function(pid, in, fd[1]));
}

void	executor(t_btree *root, int node, int *fd)
{
	static int	input;
	int			pid;

	if (node == ROOT)
		input = -1;
	if (root == NULL)
		return ;
	executor(root->l_child, LEFT_NODE, fd);
	executor(root->r_child, RIGHT_NODE, fd);
	if (root->num == CMD)
	{
		if (root->index != 0)
			pipe(fd);
		pid = execute(root->content, root->index, fd, input);
		if (root->index == 0)
		{
			ignore_signal();
			waitpid(pid, &g_exit_stat[0], 0);
		}
		input = fd[0];
		return ;
	}
}

void	execute_thesimplest(int pid, t_token **token, char **cmd)
{
	extern char	**environ;
	char		*path;

	path = NULL;
	if (pid == 0)
	{		
		if (redirect(get_redirection(token)) == 1)
			exit(127);
		if (is_path(cmd[0]) == 0)
			path = &cmd[0][0];
		else
			path = get_path(cmd[0]);
		if (!path || access(path, X_OK) == -1)
		{
			perror("shell");
			exit(127);
		}
		execve(path, cmd, environ);
		exit(127);
	}
	free_2d_table(cmd);
}

int	single_exec(t_token **token)
{
	char	**cmd;
	int		pid;

	expander(token);
	cmd = join_tokens(token);
	remember_redi(0);
	if (redirect(get_redirection(token)) == 1)
		return (remember_redi(1), 1);
	if (!cmd)
		return (remember_redi(1), 1);
	if (is_builtin(cmd[0]) == 0)
	{
		g_exit_stat[3] = exec_built(cmd);
		g_exit_stat[0] = -99;
		remember_redi(1);
		free_2d_table(cmd);
		return (1);
	}
	pid = ft_fork();
	execute_thesimplest(pid, token, cmd);
	ignore_signal();
	waitpid(pid, &g_exit_stat[0], 0);
	remember_redi(1);
	return (1);
}
