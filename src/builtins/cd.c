/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:16:48 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:16:04 by sel-kham         ###   ########.fr       */
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

static void	optimize_code(char *oldpwd)
{
	char	*pwd;

	pwd = get_cwd(1024);
	edit_env_var("PWD", pwd);
	edit_env_var("OLDPWD", oldpwd);
	free(pwd);
}

int	ft_cd(char **args)
{
	char		*home_path;
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
			optimize_code(oldpwd);
			return (free(oldpwd), 0);
		}
		return (free(oldpwd), perror("HOME: "), 1);
	}
	if (!chdir(args[1]))
	{
		optimize_code(oldpwd);
		return (free(oldpwd), 0);
	}
	return (free(oldpwd), perror("Directory"), 1);
}
