/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 15:14:45 by ozahir           ###   ########.fr       */
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
        printf("str (%s)\n", cmd);
        // add_history(cmd);
        // if (cmd)
        //     {
        //         parser(cmd, env);
        //         free(cmd);
        //     }
        
    }
}