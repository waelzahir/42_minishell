/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/28 14:24:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    shell_loop(char *prompt, char   **env)
{
    char    *cmd;
    sort_env(env);
    while (1)
    {
        cmd = readline(prompt);
        cmd =  closing_check(cmd);
        if (env)
        add_history(cmd);
        if (cmd)
            {
                print_toks(cmd , env);
                free(cmd);
            }
        
    }
}