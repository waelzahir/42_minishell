/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/30 18:30:34 by ozahir           ###   ########.fr       */
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
   
    
    while (1)
    {
         line = readline("hi % ");
        lexer = init_lexer(line , envp);
         token = lexer_get_token(lexer);
         while (token != NULL)
         {
               token = lexer_get_token(lexer);
            printf("%s, %d \n", token->val, token->tok);
         }
        free(line);
    }

    
}