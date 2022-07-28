/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:02:50 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/27 18:16:44 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"






int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


int env_size(char   **env)
{
    int i;

    i = 0;
    while(env[i])
        i++;   
    return (i);
}
void	sort_env(char **env)
{
	char	*p;
	int		i;
	int		k;
	int		size;

	k = 0;
	size = env_size(env) - 1;
	i = 1;
	while (i <= size - 1)
	{
		k = i + 1;
		while (k <= size)
		{
			if (ft_strcmp(env[i], env[k]) > 0)
			{
				p = env[i];
				env[i] = env[k];
				env[k] = p ;
			}
			k++;
		}
		i++;
	}
}
char    *get_cwd()
{
    char    *t_path;
    char    *path;

    t_path = malloc(2048);
    if (!t_path)
        return (NULL);
    getcwd(t_path, 2047);
    if (!t_path)
        return (free(t_path), NULL);
    path = ft_strdup(t_path);
    free(t_path);
    if (!path)
        return (NULL);
    return (path);
}

char    **trial_env(void)
{
    char    *path;
    char    **envp;

    
    path = get_cwd();
    if (!path)
        return (NULL);
    envp = malloc(sizeof(char   *)* 5);
    if (!envp)
        return (free(path), NULL);
    envp[0] = ft_strjoin("PWD=", path);
    envp[1] = ft_strjoin("OLDPWD=", path);
    free(path);
    envp[2] = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
    envp[3] = ft_strdup("SHLVL=1");
    envp[4] = NULL;
    return  (envp);
}

/* the env need to be duplicated*/
char    **set_env(char  **envp)
{
    if (envp[0] == NULL)
        return (trial_env());
    return (envp);
}


//getenv result cant be freed
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