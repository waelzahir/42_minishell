/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:50:15 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/27 18:40:37 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token *get_token(t_tok type, char *content, t_tok prev)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->prev = prev;
    token->type = type;
    token->content = content;
    return (token);
}

int is_token(char   c)
{
    if (c == '|' || c == '$' || c == 39 || c == '<' || c == '>' || c == 34 || c == ' ')
        return (1);
    return (0);
}