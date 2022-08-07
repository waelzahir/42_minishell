/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:39:44 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 21:43:09 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void    *shell(char *prompt, char   **env)
{
    char    *line;
    
    while (1)
    {
        line = readline(prompt);
        if (line)
        {
            add_history(line);
            parser(line,env);
        }    
    }
}