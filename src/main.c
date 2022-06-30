/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/30 19:27:59 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int main(int ac, char **av, char    **envp)
{
    char    *line;
    t_lexer *lexer;
    t_token *token = NULL;

    if (ac || av || envp)
        printf("hello \n");
   
    
    while (1)
    {
         line = readline("hi % ");
        lexer = init_lexer(line , envp);
         token = lexer_get_token(lexer);

         while (token != NULL)
         {
               printf("%s, %d \n", token->val, token->tok);
               token = lexer_get_token(lexer);
                     

            
         }
        free(line);
    }

    
}