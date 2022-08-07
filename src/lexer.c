/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:41:12 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 19:57:37 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_lexer *lexer_init(char *input, char   **env)
{
    t_lexer *lexer;

    if (!input)
        return (NULL);
    lexer = malloc(sizeof(t_lexer));
    if (!lexer)
        return (NULL);
    lexer->env = env;
    lexer->input = input;
    lexer->index = 0;
    lexer->c = input[0];
    return (lexer);
}

void    advance(t_lexer *lexer)
{
    lexer->index++;
    lexer->c = lexer->input[lexer->index];
}

void    skip_ws(t_lexer *lexer)
{
    while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
        advance(lexer);
}

char    *get_argn(t_lexer *lexer)
{
    char    *str;

    str = char_to_str(lexer->c);
    if (!str)
        return (NULL);
    advance(lexer);
    while (!is_token(lexer->c))
    {
        str = char_append(str, lexer->c);
        if (!str)
            return (NULL);
        advance(lexer);
    }
    return (str);
}

char    *get_argd(t_lexer *lexer)
{
    char    *str;

    advance(lexer);
    if (lexer->c == 34)
    {
        str = ft_calloc(1,1);
        if (!str)
            return (NULL);
        return (advance(lexer), str);
    }
    str = char_to_str(lexer->c);
    if (!str)
        return (NULL);
    advance(lexer);
    while (lexer->c != 34)
    {
        str = char_append(str, lexer->c);
        if (!str)
            return (NULL);
        advance(lexer);
    }
    advance(lexer);
  
    return (str);
}


