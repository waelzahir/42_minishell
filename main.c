/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:51:49 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/27 17:58:09 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int    ac, char    **av, char  **envp)
{
    char    **env;
    char    *prompt;

    if (ac && av)
    {
        env = set_env(envp);
        if (!env)
            return  (0);
        prompt = get_prompt();
        if (!prompt)
            return (0);
        shell_loop(prompt, env);    
    }
}