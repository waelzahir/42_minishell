/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:36:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/11 19:44:47 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char    *get_string(t_lexer *lexer)
{
    char    *str;
    
    str = NULL;
    if (lexer->c == '$')
        return  (get_var(lexer));
    str = char_to_str(lexer->c);
    advance(lexer);
    while(lexer->c != '\0' && lexer->c != '$')
    {
        str = char_append(str, lexer->c);
        advance(lexer);
    }
    return str;
}    

char    *expander(char  *s, char    **env)
{
    t_lexer *lexer;
    char    *ret;
    char    *str;
    
    ret = NULL;
    str = NULL;
    lexer = lexer_init(s, env);
    while (lexer->c != '\0')
    {
        str = get_string(lexer);
        ret = ft_strjoin(ret, str);
        free(str);
    }
    free(lexer);
    free(s);
    return (ret);
}