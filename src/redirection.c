/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:50 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/29 23:50:12 by ozahir           ###   ########.fr       */
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
        return (1);
    fd = open(str, O_RDONLY, 0777);
    if (fd < 0 || dup2(fd, 0) == -1)
    {
            perror("redirection");
            return (1);
    }
    close(fd);

    return (0);
}

int redirect_output(char    *file)
{
    int i;
    int fd;
    char    *str;

    i = -1;
    fd = -1;
    while (file[++i] == '>');
    str = clean_string(file + i);
    if (!str)
        return 1;
    if (i == 1)
        {
            unlink(str);
            fd = open(str, O_CREAT | O_WRONLY, 0777);
        }
    else if (i == 2)
        fd = open(str, O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (fd < 0 || dup2(fd, 1) == -1)
    {
        perror("redirection");
        return (1);
    }
    close(fd);
    return (0);
}

int redirect(char   **files)
{
    int i;
    int stat;

    i = 0;
    stat = 0;
    if (!files)
        return(0);
    while (files[i] && !stat)
    {
        if (files[i][0] == '>')
            stat = redirect_output(files[i]);
        else if (files[i][0] == '<')
            stat = redirect_input(files[i]);
        else
            stat = apply_herdoc(files[i]);    
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
    free(red);
    return (rdrec);
}