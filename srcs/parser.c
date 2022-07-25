/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 15:39:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
char    *closing_check(char *str)
{
    int type;
    int i;
    int    state;

    type = 0;
    i = 0;
    state = 0;
    while (str[i])
    {
        if ((str[i] == 39 || str[i] == 34) && state == 0)
        {
            state = 1;
            type = str[i];
            i++;
        }
        if (str[i] == type && state == 1)
            state = 0;
        i++;
    }
   
    if (state)
     str = ft_strjoin(str, q_prompt(type));
        
    return str;
}
void    parser(char *cmd, char  **env)
{
    t_lexer *lexer;
    t_token *token;
    lexer = init_lex(cmd, env);
    token = tokenizer(lexer);
    while (token->type != 5)
    {
        printf("type: %d | content: %s ,\n", token->type, token->content);
        token = tokenizer(lexer);
    }
    printf("type: %d | content: %s ,\n", token->type, token->content);
}