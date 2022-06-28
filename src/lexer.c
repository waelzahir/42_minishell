/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:30:21 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/28 21:46:40 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_lexer    *init_lexer(char *source, char   **envp)
{
    t_lexer *lex;

    if (!lex)
        return (NULL);
    lex->envp = envp;
    lex->index = 0;
    lex->source = source;
    lex->c = lex->source[lex->index];
    return (lex);
}

void    increment_lex(t_lexer *lexer)
{
    lexer->index++;
    lexer->c = lexer->source[lexer->index];
}

void    lex_white_spaces(t_lexer *lexer)
{
    while (lexer->c == ' ')
        increment_lex(lexer);
}

char    *get_char(char  *c)
{
    char    *str;

    str = ft_calloc(1, 2);
    if (!str)
        return (NULL);
    str[0] = c;
    return (str);
}


char    *get_str_dquote(t_lexer *lexer)
{
    char    *str;
    
    increment_lex(lexer);
    str = get_char(lexer->c);
    increment_lex(lexer);
    while (lexer->c != 34 || lexer->c != '\0')
    {
        str  = str_append(str, lexer->c);
        increment_lex(lexer);
        if (lexer->c == '$')
            str = ft_strjoin(str, get_var(lexer)); /*if the get var == NULL nothing should be appended if the char  after */
    }
    if (lexer->c == '\0')
        ft_strjoin(str, dquote_prompt());
    return  (str);
}






char    *get_str_quote(t_lexer *lexer)
{
    char    *str;

    increment_lex(lexer);
    str = get_char(lexer->c);
    while (lexer->c != 39 || lexer->c != '\0')
    {
        str = str_append(str, lexer->c);
        increment_lex(lexer);
    }
    if (lexer->c == '\0')
        ft_strjoin(str, quote_prompt());
    return (str);
}







char    *get_var(t_lexer *lexer)
{
    char    *str;

    increment_lex(lexer);
    if (lexer->c == ' ' || lexer->c == '\0')
        return (get_char('$'));
    if (lexer->c == '?')
        return (var_pointer("exit", lexer->envp));
    str = get_char(lexer->c);
    increment_lex(lexer);
    while ((lexer->c !=  34 || lexer->c != ' '| && lexer-> != '\0')
    {
        str = str_append(str, lexer->c);
        increment_lex(lexer);
    }
    return  (var_pointer(str, lexer->envp));
}



char  *str_append(char  *str, char  c)
{
  char  *ret;
  int len;

  len = strlen(str);
  ret = calloc(1, len + 2);
  memcpy(ret, str, len);
  ret[len] = c;
  return ret;
}