/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:50:15 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/23 20:30:11 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token *get_token(t_tok type, char *content)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->type = type;
    token->content = content;
    return (token);
}

int is_token(char   c)
{
    if (c == '|' || c == '$' || c == 39 || c == '<' || c == '>' || c == 43 || c == ' ')
        return (1);
    return (0);
}