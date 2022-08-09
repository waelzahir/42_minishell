/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:30:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/09 22:03:33 by sel-kham         ###   ########.fr       */
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
void    print_s(t_token **n)
{

    int i = 0;

    while (n[i])
    {
        
        printf("%s\n", n[i]->def);
        i++;
    }
    
}

void    parser(char *str, char  **env)
{
    t_stack *cmd_stack;
    t_stack *op_stack;
    t_lexer *lexer;

    lexer = lexer_init(str, env);
    if (!lexer)
        return ;
    cmd_stack = init_stack();
    if (!cmd_stack)
    {
        free(lexer);
        return ;
    }
    op_stack = init_stack();
    if (!op_stack)
    {
        free(cmd_stack);
        free(lexer);
        return ;
    }
    while (lexer->c != '\0')
    {
        push_stack(cmd_stack, fill_stacks(op_stack, lexer));
    }
    // ast = build_ast(t_stack *cmd_stack, t_stack *op_stack);
    // return (ast);
}

