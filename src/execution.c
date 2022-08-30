/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:10:29 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/30 14:46:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"


 
int is_built(char   **cmd, char **redirection, int  *fd)
{
    size_t  len;
    int     ret;

    len = ft_strlen(cmd[0]);
    ret = 1;
    redirection = NULL;
    if (len == ft_strlen("echo") && ft_strncmp(cmd[0], "echo", len) == 0)
        ret = ft_echo(cmd);
    else if (len == ft_strlen("cd") && ft_strncmp(cmd[0], "cd", len) == 0)
        ret = ft_cd(cmd);
    else if (len == ft_strlen("pwd") && ft_strncmp(cmd[0], "pwd", len) == 0)
        ret = ft_pwd(1024);
    else if (len== ft_strlen("export") && ft_strncmp(cmd[0], "export", len) == 0)
        ret = ft_export(cmd);
    else if (len == ft_strlen("unset") && ft_strncmp(cmd[0], "unset", len) == 0)
        ret = ft_unset(cmd);
    else if (len== ft_strlen("env") && ft_strncmp(cmd[0], "env", len) == 0)
        ret = ft_env();
    else if (len == ft_strlen("exit") && ft_strncmp(cmd[0], "exit", len) == 0)
        exit(0); //TODO: Handle exit builtin
    else if (fd)
        return (-1);
     return (ret);
}

int    execute(t_token **token, int node, int *fd, int in)
{
    char    **command;
    extern char **environ;
    char    *path;
  int pid;


    expander(token);
    command = join_tokens(token);
    if (is_path(command[0]) == 0)
        path = &command[0][0];
    else
        path = get_path(command[0]);
    pid = ft_fork();
    if (pid == 0)
    {
        if (access(path, X_OK) == -1)
            return (perror("shell"), exit(127), -1);
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
        if ( redirect(get_redirection(token)) == 1)
            exit(127);
        execve(path, command, environ);
        perror("execve");
        exit(127);
    }
    close(in);
    close(fd[1]);
     return (pid);
}

void    executor(t_btree *root, int node, int *fd)
{
    static int input;
    int pid;

    if (node == ROOT)
        input  = -1;
    if (root == NULL)
        return ;
    executor(root->l_child, LEFT_NODE, fd);
    executor(root->r_child, RIGHT_NODE, fd);
    if (root->num == CMD)
    {
        if (root->index != 0)
            pipe(fd);
        pid  = execute(root->content, root->index, fd, input);
        if (root->index == 0)
            waitpid(pid, &exit_stat[0],0);
        input = fd[0];
        return ;
    }
}
