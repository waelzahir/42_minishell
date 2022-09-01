/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:10:29 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/31 22:28:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"


 
int is_builtin(char   *cmd)
{
    size_t  len;
    if (!cmd)
        return (1);
    len = ft_strlen(cmd);
    if (len == ft_strlen("echo") && ft_strncmp(cmd, "echo", len) == 0)
        return (0);
    else if (len == ft_strlen("cd") && ft_strncmp(cmd, "cd", len) == 0)
        return (0);
    else if (len == ft_strlen("pwd") && ft_strncmp(cmd, "pwd", len) == 0)
        return (0);
    else if (len== ft_strlen("export") && ft_strncmp(cmd, "export", len) == 0)
        return (0);
    else if (len == ft_strlen("unset") && ft_strncmp(cmd, "unset", len) == 0)
        return (0);
    else if (len== ft_strlen("env") && ft_strncmp(cmd, "env", len) == 0)
        return (0);
    else if (len == ft_strlen("exit") && ft_strncmp(cmd, "exit", len) == 0)
        return (0);
     return (1);
}

int exec_built(char **cmd)
{
    size_t  len;
    int     ret;
    // char    **cmd;

    len = ft_strlen(cmd[0]);
    ret = -1;
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
     return (ret);
}

void    pipe_helper(int node, int *fd, int in)
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
int    execute(t_token **token, int node, int *fd, int in)
{
    char    **command;
    extern char **environ;
    char    *path;
    int pid;


    expander(token);
    pid = ft_fork();
    if (pid == 0)
    {
        pipe_helper(node, fd, in);
        if (redirect(get_redirection(token)) == 1)
            exit(127);
        command = join_tokens(token);
        if (!command)
            exit(127);
             if (is_path(command[0]) == 0)
        path = &command[0][0];
    else
        path = get_path(command[0]);
    if (!path || access(path, X_OK) == -1)
            return (perror("shell"), exit(127), -1);
    if (!is_builtin(command[0]))
    {
        exit_stat[3] = exec_built(command);
        exit(0);
    }
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
void    execute_thesimplest(int pid, t_token  **token, char **cmd)
{
    extern  char    **environ;
    char            *path;
    
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
}
void    single_exec(t_token     **token)
{
    char    **cmd;
    int     pid;

    expander(token);
    cmd = join_tokens(token);
    if (!cmd)
        return ;
    if (is_builtin(cmd[0]) == 0)
    {
        remember_redi(0);
        if (redirect(get_redirection(token)) == 1)
        {
            remember_redi(1);
            return ;
        }
        exit_stat[3] = exec_built(cmd);
        remember_redi(1);
        return ;
    }
    pid = ft_fork();
    execute_thesimplest(pid, token, cmd);
    waitpid(pid, &exit_stat[0], 0);
}

void    exe_launcher(t_btree *root, int mode, int *fd)
{
    if (root->num == CMD)
    {
        single_exec(root->content);        
    }
    else
        executor(root, ROOT, fd);
}