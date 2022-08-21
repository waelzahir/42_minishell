/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:56 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 17:30:58 by sel-kham         ###   ########.fr       */
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
