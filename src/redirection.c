/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:50 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/29 00:22:43 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char    *clean_string(char  *s)
{
    char    *string;
    int i;
    
    i = 0;
    if (s[0] == 34 || s[0] == 39)
        string = s + 1;
    else
        return (s);
    while (string[i])
        i++;
    string[i - 1] = 0;
    return string;
}

int     here_doc(char   *str, int exp, char	*prompt)
{
    char    *line;
    int     fd[2];
    size_t i;

    prompt = NULL;
    line = NULL;
    i = ft_strlen(str);
    if (pipe(fd) == -1)
        return (perror("pipe"), 0);
	ft_putstr_fd(line, exit_stat[2]);
    line = get_next_line(exit_stat[1]);
    while (line)
    {
        if (ft_strncmp(str, line , i) == 0 && i == ft_strlen(line))
            break ;
        if (exp == 0)
            line = expand(line);
        ft_putstr_fd(line, fd[1]);
		free(line);
		ft_putstr_fd(line, exit_stat[2]);
        line = get_next_line(exit_stat[1]);
    }
    close(fd[1]);
    dup2(fd[0], 0);
	close(fd[0]);
	free(line);
    return (0);
}
int redirect_input(char *file)
{
    int i;
    int fd;
    int exp;
    char    *str;

    i = -1;
    exp = 1;
    fd = -1;
    while (file[++i] == '<');
    if (file[i] == 34 || file[i] == 39)
        exp = 0;
    str = clean_string(file + i);
    if (!str)
        return 1;
    if (i == 1)
    {
        fd = open(str, O_RDONLY, 0777);
        if (fd < 0 || dup2(fd, 0) == -1)
        {
            perror("redirection");
            return (1);
        }
    }
    else if (i == 2)
        return (here_doc(str, exp, "heredoc>"));
    return (0);
}

int redirect_output(char    *file)
{
    int i;
    int fd;
    char    *str;

    i = -1;
    fd = -1;
    while (file[++i] == '<');
    str = clean_string(file + i);
    if (!str)
        return 1;
    if (i == 1)
        fd = open(file, O_CREAT | O_WRONLY, 0777);
    else if (i == 2)
        fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (fd < 0 || dup2(fd, 1) == -1)
    {
        perror("redirection");
        return (1);
    }
    return (0);
}

int redirect(char   **files)
{
    int i;
    int stat;

    i = 0;
    stat = 0;
    while (files[i] && !stat)
    {
        if (files[i][0] == '>')
            stat = redirect_output(files[i]);
        else if (files[i][0] == '<')
            stat = redirect_input(files[i]);
        i++;
        if (stat == 1)
            return(1);
    }
    return (0);
}
char    **get_redirection(t_token    **token)
{
    t_stack		*red;
    char		**rdrec;
    int			i;

    i = 0;
    red = init_stack();
    if (!red)
        return (NULL);
    while (token[i])
    {
        if (token[i]->type == redirec)
                push_stack(red, ft_strdup(token[i]->def));
        i++;
    }
    if (red->size == 0)
        return (free(red),  NULL);
    rdrec = (char   **)red->stack;
    return (rdrec);
}