/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:26:56 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 18:51:34 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

/*
 * Init envirement by OLDPWD PWD SHLVL in case env passed NULL by env -i
 */
void	init_env(void)
{
	extern char	**environ;
	char		**new_env;
	int			i;

	if (!environ)
		return ;
	if (!environ[0])
		return ;
	i = size_counter(environ);
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	i = -1;
	while (environ[++i])
		new_env[i] = ft_strdup(environ[i]);
	new_env[i] = NULL;
	environ = new_env;
}

char	**arg_to_hash(char *arg)
{
	int		i;
	char	**hash;
	
	i = -1;
	hash = (char **) malloc(sizeof(char *) * 4);
	if (!hash)
		exit (EXIT_FAILURE);
	while (arg[++i])
		if (arg[i] == '=')
			break ;
	hash[0] = ft_substr(arg, 0, i);
	if (!arg[i + 1])
		hash[1] = NULL;
	else
		hash[1] = ft_substr(arg, i + 1, ft_strlen(arg));
	hash[2] = ft_calloc(1, 3);
	hash[3] = NULL;
	if (!hash[0])
		exit(EXIT_FAILURE);
	if (hash[0][ft_strlen(hash[0]) - 1] == '+')
	{
		hash[0][i - 1] = 0;
		hash[2][0] = '+';
	}
	if (arg[i] == '=' )
		hash[2][1] = '=';
	return (hash);
}

void	add_env_var(char *id, char *value)
{
	extern char	**environ;
	char		**new_env;
	int			i;

	i = size_counter(environ);
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		exit(EXIT_FAILURE);
	i = -1;
	while (environ[++i])
		new_env[i] = environ[i];
	if (!value)
		new_env[i] = ft_strdup(id);
	else
	{
		new_env[i] = ft__strjoin(ft_strjoin(id, "="), value);
	}
	if (!new_env[i])
		exit(EXIT_FAILURE);
	new_env[i + 1] = NULL;
	if (environ[0])
		free(environ);
	environ = new_env;
}

char	*get_env_var(char *id)
{
	extern char	**environ;
	int			len;
	int			i;

	if (!environ)
		return (NULL);
	if (!environ[0])
		return (NULL);
	len = ft_strlen(id);
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(id, environ[i], len)
			&& (environ[i][len] == '=' || environ[i][len] == '\0'))
			return (environ[i]);
	}
	return (NULL);
}

void	delete_env_var(char *id)
{
	extern	char	**environ;
	t_stack	*stack;
	t_stack	*temp;
	char	*poin;

	stack = ft_calloc(1, sizeof(t_stack));
	temp = ft_calloc(1, sizeof(t_stack));
	stack->stack = (void **) environ;
	stack->size = size_counter(environ);
	while (stack->size)
	{
		poin = pop_stack(stack);
		if (!ft_strncmp(id, poin, ft_strlen(id)) \
			&& (poin[ft_strlen(id)] == '=' || poin[ft_strlen(id)] == '\0'))
		{
			free(poin);
			break ;
		}
		else
			push_stack(temp, poin);
	}
	while (temp->size != 0)
		push_stack(stack, pop_stack(temp));
	environ = (char **) stack->stack;
	free(stack);
	free(temp);
}

void	edit_env_var(char *id, char *value)
{
	delete_env_var(id);
	add_env_var(id, value);
}

void	append_env_var(char *id, char *value)
{
	extern char	**environ;
	char		*tmp;
	int			len;
	int			i;

	len = ft_strlen(id);
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(id, environ[i], len)
			&& (environ[i][len] == '=' || environ[i][len] == '\0'))
		{
			tmp = environ[i];
			if (environ[i][len] == '\0')
				environ[i] = ft__strjoin(ft_strjoin(tmp, "="), value);
			else
				environ[i] = ft_strjoin(tmp, value);
			free(tmp);
			return ;
		}
	}
}
