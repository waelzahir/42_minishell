/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:56 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/22 04:00:22 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	**init_env()
{
	extern char	**environ;
	char		**new_env;
	int			i;

	i = -1;
	while (environ[++i])
		;
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
				hash = arg_to_hash(environ[i]);
	}
	return (hash);
}

char	**new_env_var(char **var)
{
	extern char	**environ;
	char		**new_env;
	int			i;

	i = -1;
	while (environ[++i])
		;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
	new_env[i] = ft_strjoin(ft_strjoin(var[0], "=\""), \
					ft_strjoin(var[1], "\""));
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
	unset(env_var[0]);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
	new_env[i] = ft_strjoin(ft_strjoin(ft_strjoin(env_var[i], "=\""), ft_strjoin(env_var[2], var[2])), "\"");
	if (!new_env[i])
		exit(EXIT_FAILURE);
	new_env[i + 1] = NULL;
	free_2d_table(env_var);
	return (new_env);
}
