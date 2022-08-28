/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:08:14 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 22:41:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int    is_path(char    *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '/')
            return (0);
            i++;
    }
    return (1);
}

char	*path_join(char const *s1, char const *s2, int c)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	ss = malloc((ln1 + ln2) * sizeof(char) + 2);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s1, ln1);
	ss[ln1] = c;
	ln1++;
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	return (ss);
}
char	*binary_path(char	*cmd, char	**paths)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = path_join(paths[i], cmd, '/');
		if (!path)
			return (ft_putstr_fd("malloc error\n", 2), NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}


char	*get_path(char	*cmd)
{
	char	*path;
	char	**d_binaries;
    char    *paths;
    
    paths = getenv("PATH");
    if (!paths)
        return (NULL);
	d_binaries = ft_split(paths, ':');
	if (!d_binaries)
		return (NULL);
	path = binary_path(cmd, d_binaries);
	if (!path)
		return (NULL);
	return (path);
}

void    path_included(char **command, char **redirection, int *fd)
{
    extern char **environ;

    redirection = NULL;
        if (fd)
           {
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
           }
        execve(command[0], command, environ);
        perror("execve :");
        exit(1);
    
}