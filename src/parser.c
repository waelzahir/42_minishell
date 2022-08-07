/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:30:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 21:49:26 by ozahir           ###   ########.fr       */
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
        return (skip_ws(lexer), set_token(space, char_to_str(' ')));
    if (lexer->c == 34)
        return  (set_token(darg, get_argd(lexer)));
    if (lexer->c == 39)
        return (set_token(qarg, get_argq(lexer)));
    if (lexer->c == '|')
        return (set_token(pip, get_pipe(lexer)));
    if (lexer->c == '<')
        return (set_token(input, get_red(lexer, '<')));
    if (lexer->c == '>')
        return (set_token(output, get_red(lexer, '>')));
    return (set_token(arg, get_argn(lexer)));
}


void    parser(char *str, char  **env)
{
    t_stack *stack;
    
    t_lexer *lexer;
    t_token **tokens;

    lexer = lexer_init(str, env);
    stack = init_stack();
    
    while (lexer->c != '\0')
    {
        push_stack(stack, tokenizer(lexer));
    }
    int i = 0;
    tokens = (t_token **)stack->stack;
    while (tokens[i])
    {
        printf("%s | type %d \n", tokens[i]->def, tokens[i]->type);
        i++;
    }
}