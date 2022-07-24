/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:02:50 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 14:33:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    **trial_env(void)
{
    char    *path;
    char    **envp;

    path = malloc(2048);
    if (!path)
        return (NULL);
    getcwd(path, 2047);
    if (!path)
        return (NULL);
    envp = malloc(sizeof(char   *)* 5);
    if (!envp)
        return (NULL);
    envp[0] = ft_strjoin("PWD=", path);
    envp[1] = ft_strjoin("OLDPWD=", path);
    free(path);
    envp[2] = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
    envp[3] = ft_strdup("SHLVL=1");
    envp[4] = NULL;
    return  (envp);
}
char    **set_env(char  **envp)
{
    if (envp[0] == NULL)
        return (trial_env());
    return (envp);
}

char    *get_prompt(void)
{
    char    *user;
    char    *prompt;
    
    user = getenv("USER");
    if (!user)
        return (ft_strdup("trial@1337 % "));
    prompt = ft_strjoin(user, "@1337 % ");
    return prompt;
}