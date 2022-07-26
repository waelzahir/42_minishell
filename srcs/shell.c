/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/26 22:49:48 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    shell_loop(char *prompt, char   **env)
{
    char    *cmd;
    while (1)
    {
        cmd = readline(prompt);
        cmd =  closing_check(cmd);
        if (env)
       // add_history(cmd);
        if (cmd)
            {
                parser(cmd, env);
                free(cmd);
                system("leaks minishell");
            }
        
    }
}