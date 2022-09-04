/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:10:29 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/04 16:56:41 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	is_builtin(char *cmd)
{
	size_t	len;

	if (!cmd)
		return (1);
	len = ft_strlen(cmd);
	if (len == ft_strlen("echo") && ft_strncmp(cmd, "echo", len) == 0)
		return (0);
	else if (len == ft_strlen("cd") && ft_strncmp(cmd, "cd", len) == 0)
		return (0);
	else if (len == ft_strlen("pwd") && ft_strncmp(cmd, "pwd", len) == 0)
		return (0);
	else if (len == ft_strlen("export") && ft_strncmp(cmd, "export", len) == 0)
		return (0);
	else if (len == ft_strlen("unset") && ft_strncmp(cmd, "unset", len) == 0)
		return (0);
	else if (len == ft_strlen("env") && ft_strncmp(cmd, "env", len) == 0)
		return (0);
	else if (len == ft_strlen("exit") && ft_strncmp(cmd, "exit", len) == 0)
		return (0);
	return (1);
}

int	exec_built(char **cmd)
{
	size_t	len;
	int		ret;

	len = ft_strlen(cmd[0]);
	ret = -1;
	if (len == ft_strlen("echo") && ft_strncmp(cmd[0], "echo", len) == 0)
		ret = ft_echo(cmd);
	else if (len == ft_strlen("cd") && ft_strncmp(cmd[0], "cd", len) == 0)
		ret = ft_cd(cmd);
	else if (len == ft_strlen("pwd") && ft_strncmp(cmd[0], "pwd", len) == 0)
		ret = ft_pwd(1024);
	else if (len == ft_strlen("export") \
			&& ft_strncmp(cmd[0], "export", len) == 0)
		ret = ft_export(cmd);
	else if (len == ft_strlen("unset") && ft_strncmp(cmd[0], "unset", len) == 0)
		ret = ft_unset(cmd);
	else if (len == ft_strlen("env") && ft_strncmp(cmd[0], "env", len) == 0)
		ret = ft_env();
	else if (len == ft_strlen("exit") && ft_strncmp(cmd[0], "exit", len) == 0)
		ret = ft_exit(cmd);
	return (ret);
}

void	exe_launcher(t_btree *root, int mode, int *fd)
{
	if (root->num == CMD)
	{
		mode = 0;
		single_exec(root->content);
	}
	else
		executor(root, ROOT, fd);
}

char	*set_path(char *cmd)
{
	char	*path;

	if (is_path(cmd) == 0)
		path = &cmd[0];
	else
		path = get_path(cmd);
	if (!path || access(path, X_OK) == -1)
		return (perror("shell"), exit(127), NULL);
	return (path);
}

int	return_function(int pid, int in, int fd)
{
	if (in != -1)
		close(in);
	close(fd);
	return (pid);
}
