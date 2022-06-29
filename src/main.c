/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/29 20:46:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int main(int ac, char **av, char    **envp)
{
    char    *line;
    t_lexer *lexer;
    t_token *token;

    if (ac || av || envp)
        printf("hello \n");
    line = readline("hi % ");
    lexer = init_lexer(line , envp);
    token = lexer_get_token(lexer);
    while (token != NULL)
    {
        printf("%s, %d \n", token->val, token->tok);
            token = lexer_get_token(lexer);

        
    }

    
}