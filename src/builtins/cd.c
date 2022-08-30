/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:16:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/30 04:25:32 by sel-kham         ###   ########.fr       */
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

char	**update_pwd(char *id, char *val)
{
	char		**hash;
	
	hash = malloc(sizeof (char *) * 3);
	if (!hash)
		exit(EXIT_FAILURE);
	hash[0] = ft_strdup(id);
	hash[1] = val;
	hash[2] = NULL;
	return (edit_env_var(hash));
}

int	ft_cd(char **args)
{
	char	*home_path;
	char	*pwd;
	char	*oldpwd;

	if (!args)
		return (1);
	pwd = get_cwd(1024);
	if (!args[1])
	{
		home_path = getenv("HOME");
		if (!home_path)
		{
			perror("Home");
			return (1);
		}
		if (!chdir(home_path))
		{
			oldpwd = get_cwd(1024);
			return (0);
		}
		perror("HOME: ");
		return (1);
	}
	if (!chdir(args[1]))
		return (0);
	perror("Directory");
	return (1);
}
