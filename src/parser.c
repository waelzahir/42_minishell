/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:30:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/03 20:01:17 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_token *tokenizer(t_lexer  *lexer)
{
    if (lexer->index == 0)
        skip_ws(lexer);
    if (lexer->c == '\0')
        return (set_token(end, NULL));
    if (lexer->c == ' ')
        return (skip_ws(lexer), set_token(space, char_to_str(' '));
    if (lexer->c == 34)
        return  (set_token(darg, get_argd(lexer)));
    if (lexer->c == 39)
        return (set_token(qarg, get_argq(lexer)));
    if (lexer->c == '|')
        return (advance(lexer), set_token(pipe, get_pipe));
    if (lexer->c == '<')
        return (set_token(input, get_input(lexer)));
    if (lexer->c == '>')
        return (set_token(output, get_output(lexer)));
    if (lexer->c == '$')
        return (set_token(var, get_var))
    return (set_token(arg, get_argn(lexer)));
}