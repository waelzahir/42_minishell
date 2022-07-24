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
}