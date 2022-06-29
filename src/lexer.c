/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:30:21 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/29 20:48:57 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"


t_lexer    *init_lexer(char *source, char   **envp)
{
    t_lexer *lex;

    lex = malloc(sizeof(t_lexer));
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
    while (lexer->c == ' '|| lexer->c == '\n')
        increment_lex(lexer);
}

char  *str_append(char  *str, char  c)
{
  char  *ret;
  int len;

    if (str)
        len = ft_strlen(str);
    else 
    len = 0;
  ret = ft_calloc(1, len + 2);
  ft_memcpy(ret, str, len);
  ret[len] = c;
  return ret;
}




char    *get_char(char  c)
{
    char    *str;

    str = ft_calloc(1, 2);
    if (!str)
        return (NULL);
    str[0] = c;
    return (str);
}




int is_token(char c)
{
    if (c == 39 || c == 34 || c == 36 || c == 60 || c == 62 || c == 124 )
        return (1);
    
return (0);
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
    while (lexer->c !=  34 || lexer->c != ' '||  lexer->c != '\0')
    {
        str = str_append(str, lexer->c);
        increment_lex(lexer);
    }
    return  (var_pointer(str, lexer->envp));
}

char    *var_pointer(char   *str, char  **envp)
{
    int len;
    int i;
    
    i = 0;
    len = ft_strlen(str);
    while (envp[i])
    {
        if (ft_strncmp(str, envp[i], len) == 0)
            return (envp[i] + len + 1);
        i++;
    }
    return (NULL);
}
char    *lexer_get_string(t_lexer *lexer, char  d)
{
    char    *str;
    str = NULL;

    increment_lex(lexer);
    while (lexer->c != d || lexer->c != '\0')
    {
        str = str_append(str, lexer->c);
        increment_lex(lexer);
    }
    return (str);
}


t_token *lexer_get_token(t_lexer *lexer)
{
    char    *str;
    str = NULL;
    lex_white_spaces(lexer);
    
    if (lexer->c == 124)
        {
            increment_lex(lexer);
            return (get_token(PIPE, get_char('|')));
        }
    if (lexer->c == 34)
        return (get_token(ARG, lexer_get_string(lexer, 34)));
    if (lexer->c == 39)
        return (get_token(ARG, lexer_get_string(lexer, 39)));
    if (lexer->c == '\0')
        return (NULL);
    while (lexer->c != '\0' && !is_token(lexer->c) && lexer->c != ' ')
    {
        str = str_append(str, lexer->c);
        increment_lex(lexer);
    }
    
    return (get_token(ARG, str));

   
    
    
}