/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:41:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/03 20:00:35 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int is_token(char   c)
{
    if (c == 39 || c == 34 || c == '|' || c == '>' || c == '<' || c == '$' || c == ' ' || c == '\0')
        return (1);
    return (0);
}
char    *char_to_str(char   c)
{
    char    *str;

    str = ft_calloc(1,2);
    if (!str)
        return NULL;
    str[0] = c;
    return (str);
}

char    *char_append(char   *str, char  c)
{
    char    *app;
    int len;

    app = NULL;
    if (!str)
        return (NULL);
    len = ft_strlen(str);
    app = malloc(len + 2);
    if (!len)
        return (free(str), NULL);
    app[len] = c;
    app[len + 1] = '\0';
    free(str);
    return (app);
}

char    *extend_var(char    *s, char    **env)
{
    char    *str;
    char    *ret;
    int     i;
    int     len;

    i = -1;
    str = ft_strjoin(s, "=");
    free(s);
    if (!str)
        return (NULL);
    len = ft_strlen(str);
    while (env[++i])
    {
        if (ft_strncmp(env[i], str, len) == 0)
        {
            if (env[i][len] != '\0');
                ret = ft_strdup(env[i] + len);
            else
                ret = ft_calloc(1,1);
            free(str);
            return (ret);
        }
    }
    free(str);
    return ft_calloc(1,1);
}

char    *get_pipe(t_lexer *lexer)
{
    char    *str;

    str = ft_calloc(1, 2);
    if (!str)
        return (NULL);
    str[0] = '|';
    return (str);
}