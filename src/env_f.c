/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:56 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/01 02:23:18 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

/*
 * Init envirement by OLDPWD PWD SHLVL in case env passed NULL by env -i
 */
char	**init_env(void)
{
	extern char	**environ;
	char		**new_env;
	int			i;

	i = -1;
	while (environ[++i])
		;
	// new_env = (char **) garbage_collector(sizeof(char *) * i, ALLOCATE);
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		exit(EXIT_FAILURE);
	i = -1;
	while (environ[++i])
		new_env[i] = ft_strdup(environ[i]);
	new_env[i] = NULL;
	return (new_env);
}

char	**arg_to_hash(char *arg)
{
	int		i;
	char	**hash;
	
	i = -1;
	// hash = (char **) garbage_collector(sizeof(char *) * 3, ALLOCATE);
	hash = (char **) malloc(sizeof(char *) * 3);
	if (!hash)
		exit (EXIT_FAILURE);
	while (arg[++i])
		if (arg[i] == '=')
			break ;
	hash[0] = ft_substr(arg, 0, i);
	hash[1] = ft_substr(arg, i + 1, ft_strlen(arg));
	hash[2] = NULL;
	if (!hash[0] || !hash[1])
		exit(EXIT_FAILURE);
	return (hash);
}

char	**is_env_var(char *arg)
{
	extern char **environ;
	char		**hash;
	int			i;

	i = -1;
	hash = NULL;
	while (environ[++i])
	{
		if (!ft_strncmp(arg, environ[i], ft_strlen(arg))
			&& environ[i][ft_strlen(arg)] == '=')
			{
				hash = arg_to_hash(environ[i]);
				break ;
			}
	}
	return (hash);
}

char	**new_env_var(char **var)
{
	extern char	**environ;
	char		**new_env;
	int			i;

	i = size_counter(environ);
	// new_env = (char **) garbage_collector(sizeof(char *) * (i + 1), ALLOCATE);
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
	new_env[i] = ft_strjoin(ft_strjoin(var[0], "="), var[1]);
	if (!new_env[i])
		exit(EXIT_FAILURE);
	new_env[i + 1] = NULL;
	return (new_env);
}

char	**edit_env_var(char **var)
{
	extern char	**environ;
	char		**new_env;
	char		**env_var;
	int			i;

	i = -1;
	while (environ[++i])
		;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		exit(EXIT_FAILURE);
	env_var = is_env_var(var[0]);
	if (env_var)
		unset(env_var[0]);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
	if (env_var)
		new_env[i] = ft_strjoin(ft_strjoin(env_var[0], "="), ft_strjoin(env_var[1], var[1]));
	else
		new_env[i] = ft_strjoin(ft_strjoin(var[0], "="), var[1]);
	if (!new_env[i])
		exit(EXIT_FAILURE);
	new_env[i + 1] = NULL;
	return (new_env);
}

char	**replace_env_var(char **var)
{
	extern char	**environ;
	char		**new_env;
	char		**env_var;
	int			i;

	i = -1;
	while (environ[++i])
		;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		exit(EXIT_FAILURE);
	env_var = is_env_var(var[0]);
	if (env_var)
		unset(env_var[0]);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
}
