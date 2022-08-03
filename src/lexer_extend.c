/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:08:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/03 17:18:26 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char    *get_argq(t_lexer   *lexer)
{
     char    *str;

    advance(lexer);
    if (lexer->c == 39)
    {
        str = ft_calloc(1,1);
        if (!str)
            return (NULL);
        return (advance(lexer), str);
    }
    str = char_to_str(lexer->c)
    if (!str)
        return (NULL);
    advance(lexer);
    while (lexer->c != 39)
    {
        str = char_append(str, lexer->c)
        if (!str)
            return (NULL);
        advance(lexer);
    }
    advance(lexer);
    return (str);
}

char    *get_var(t_lexer    *lexer)
{
    char    *str;

    str = NULL;
    advance(lexer);
    if (lexer->c == '$')
        {
            str = char_to_str('1');
            if (!str)
                return (NULL);
            return (advance(lexer), str);
        }
    if (lexer->c == '?')
    {
        str = ft_strdup("blati, azebi");
        if (!str)
            return (NULL);
        return (advance(lexer), str);
    }
    return(get_var_extend(lexer));
}

char    *get_var_extend(t_lexer *lexer)
{
    char    *str;
    
    str = NULL
    if (is_token(lexer->c))
    {
         str = char_to_str('$');
            if (!str)
                return (NULL);
            return (str);
    }
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
    str = extend_var(str);
    return (str);    
}
char    *get_input(t_lexer  *lexer)
{
    char    *str;

    str = char_to_str('<');
    if (!str)
        return (NULL);
    advance(lexer);
    while (lexer->c == '<')
    {
        str = char_append(str, '<');
        if (!str)
            return (NULL);
        advance(lexer);           
    }
    skip_ws(lexer);
    while (!is_token(lexer->c))
    {
        str = char_append(str, lexer->c);
        if (!str)
            return(NULL);
        advance(lexer);
    }
    return (str);
}
char    *get_output(t_lexer  *lexer)
{
    char    *str;

    str = char_to_str('>');
    if (!str)
        return (NULL);
    advance(lexer);
    while (lexer->c == '>')
    {
        str = char_append(str, '>');
        if (!str)
            return (NULL);
        advance(lexer);           
    }
    skip_ws(lexer);
    while (!is_token(lexer->c))
    {
        str = char_append(str, lexer->c);
        if (!str)
            return(NULL);
        advance(lexer);
    }
    return (str);
}



