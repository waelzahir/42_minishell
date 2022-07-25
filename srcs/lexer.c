/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:53:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 15:43:03 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexer *init_lex(char  *content, char  **env)
{
    t_lexer *lexer;

    lexer = malloc(sizeof(t_lexer));
    if (!lexer)
        return NULL;
    lexer->env = env;
    lexer->source = content;
    lexer->index = 0;
    lexer->c = lexer->source[lexer->index];
    return  (lexer);
}
void    advance(t_lexer *lexer)
{
    lexer->index++;
    lexer->c = lexer->source[lexer->index];
}

void    skip(t_lexer *lexer)
{
    while (lexer->c == ' ')
      advance(lexer);
}

char    *char_to_str(char   c)
{
    char    *str;

    str = malloc(2);
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char  *char_append_str(char  *str, char  c)
{
  char  *ret;
  int   len;

    if (str)
        len = ft_strlen(str);
    else 
    len = 0;
    ret = ft_calloc(1, len + 2);
    ft_memcpy(ret, str, len);
    ret[len] = c;
    free(str);
    return ret;
}

char    *get_simple_arg(t_lexer *lexer)
{
    char    *str;

    str = NULL;
    str = char_to_str(lexer->c);
    if (str == NULL)
        return NULL;
    advance(lexer);
    while (lexer->c != ' ' && !is_token(lexer->c) && lexer->c != '\0')
    {
        if (lexer->c == '$')
            {
                ft_strjoin(str, var_expand(lexer));
            }
        str = char_append_str(str, lexer->c);

        advance(lexer);
    }
    return (str);
}
char    *get_quoted_arg(t_lexer *lexer)
{
    char    *str;

    advance(lexer);
    str = char_to_str(lexer->c);
    if (lexer->c == 39)
        return (advance(lexer), free(str),char_to_str(' '));
    advance(lexer);
    while (lexer->c != 39)
    {
 
        str  = char_append_str(str, lexer->c);
        advance(lexer);
    }
    advance(lexer);
    return (str);
}
char    *get_dquoted_arg(t_lexer *lexer)
{
    char    *str;

    str = NULL;
    advance(lexer);
    if (lexer->c == '$')
    {
        str = var_expand(lexer);
    }
    if (lexer->c == 34 && str)
        return (advance(lexer), str);
    else
        return (advance(lexer),  char_to_str(' '));
    if (!str)
        str = char_to_str(lexer->c);
    advance(lexer);
    while (lexer->c != 34)
    {
        if (lexer->c == '$')
            {
                str = ft_strjoin(str, var_expand(lexer));
            }
        str = char_append_str(str, lexer->c);
        advance(lexer);
    }
    advance(lexer);
    return (str);
}

char    *get_var_pointer(char    *key, char  **env)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(key);
    while (env[i])
    {
        if (ft_strncmp(key, env[i], len) == 0)
            return (env[i] + len);
        i++;
    }
    return (NULL);
}
char    *var_expand(t_lexer *lexer)
{
    char    *str;

    str  = NULL;
    advance(lexer);
    if (lexer->c == '\0')
    return (char_to_str('$'));

    if (is_token(lexer->c))
        return (char_to_str('$'));
    if (lexer->c == '?')
        return (advance(lexer), get_var_pointer("EXSTATUS", lexer->env));
    if (lexer->c == '$')
        return (advance(lexer), char_to_str('1'));
    str = char_to_str(lexer->c);
    advance(lexer);
    while (!is_token(lexer->c) && lexer->c != '\0')
        {
            str = char_append_str(str, lexer->c);
            advance(lexer);
        }
    return (get_var_pointer(str, lexer->env));
}
int exist_one(char  *str, char  c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    if (count % 2 == 1)
        return (1);
    return (0);
}
char    *q_prompt(int quote)
{
    char    *str;
    char    *prompt;

    if (quote == 39)
        prompt = "quote>";
    if (quote == 34)
        prompt = "dquote>";
    str = readline(prompt);
    if (exist_one(str, quote) == 1)
        return (str);
    while (1)
    {
        str = ft_strjoin(str, readline(prompt));
        if (exist_one(str, quote) == 1)
            break ;
    }
    return (str);
}

t_token *tokenizer(t_lexer *lexer)
{
    if (lexer->index == 0)
        skip(lexer);
    if (lexer->c == '\0')
        return (get_token(EOL, NULL));
    if (lexer->c == ' ')
        return (skip(lexer), get_token(SPAC, char_to_str(' ')));
    if (lexer->c == 39)
        return (get_token(ARG, get_quoted_arg(lexer)));
     if (lexer->c == 34)
        return (get_token(ARG, get_dquoted_arg(lexer)));
    if (lexer->c == '|')
        return (advance(lexer), get_token(PIPE, char_to_str('|')));
    if (lexer->c == '>')
        return (advance(lexer), get_token(OUT, char_to_str('>')));
    if (lexer->c == '<')
        return (advance(lexer), get_token(IN, char_to_str('<')));
    if (lexer->c == '$')
        return (get_token(ARG, var_expand(lexer)));
    
    return (get_token(ARG,get_simple_arg(lexer)));
}