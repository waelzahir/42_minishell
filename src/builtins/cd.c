/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:16:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/01 17:57:32 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

/*
* Still needs ENV variables
*/

static char	*get_cwd(int size)
{
	char	*cwd;
	
	cwd = malloc(sizeof (char) * size);
	if (!cwd)
		exit(EXIT_FAILURE);
	if (!getcwd(cwd, size))
	{
		if (!cwd[0])
		{
			free(cwd);
			get_cwd(size + 1024);
		}
		return (cwd);
	}
	return (cwd);
}

char	**update_pwd(const char *id, char *val)
{
	char		**hash;
	
	hash = malloc(sizeof (char *) * 3);
	if (!hash)
		exit(EXIT_FAILURE);
	hash[0] = ft_strdup(id);
	hash[1] = ft_strdup(val);
	hash[2] = NULL;
	return (replace_env_var(hash));
}

int	ft_cd(char **args)
{
	char		*home_path;
	char		*pwd;
	char		*oldpwd;
	extern char	**environ;

	if (!args)
		return (1);
	oldpwd = get_cwd(1024);
	if (!args[1])
	{
		home_path = getenv("HOME");
		if (!home_path)
			return (perror("Home"), 1);
		if (!chdir(home_path))
		{
			pwd = get_cwd(1024);
			environ = update_pwd("PWD", pwd);
			environ = update_pwd("OLDPWD", oldpwd);
			return (free(pwd), free(oldpwd), 0);
		}
		return (free(oldpwd), perror("HOME: "), 1);
	}
	if (!chdir(args[1]))
	{
		pwd = get_cwd(1024);
		environ = update_pwd("PWD", pwd);
		environ = update_pwd("OLDPWD", oldpwd);
		return (free(pwd), free(oldpwd), 0);
	}
	return (free(oldpwd), perror("Directory"), 1);
}
