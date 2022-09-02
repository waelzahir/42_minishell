/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:21:40 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/28 23:53:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

/*
 * Segfault in export export var0 va1 va2 0-8 var3
 * When it is called more than once
 */

int	check_identefier(char *id)
{
	int	i;

	i = 0;
	if (id[i] && (ft_isalpha(id[i]) || id[i] == '_'))
	{
		while (id[++i] && (ft_isalnum(id[i]) || id[i] == '_'))
			;
		if (id[i] == '=' || (id[i] == '+' && id[i + 1] == '=') || !id[i])
			return (1);
	}
	return (0);
}

void	new_var(char **hash)
{
	if (hash[2][0] == '+')
		hash[0][ft_strlen(hash[0]) - 1] = 0;
	if (!hash[1])
		add_env_var(hash[0], NULL);
	else
		add_env_var(hash[0], hash[1]);
}

void	free_hash(char **hash)
{
	free(hash[0]);
	if (hash[1])
		free(hash[1]);
	free(hash[2]);
	free(hash);
}

int	export(char *arg)
{
	char	*env_var;
	char	**hash;

	if (!check_identefier(arg))
	{
		ft_putstr_fd("export: invalid identifer\n", 2);
		return (1);
	}
	hash = arg_to_hash(arg);
	env_var = get_env_var(hash[0]);
	if (!env_var)
		return (new_var(hash), 0);
	if (!hash[1] && hash[2][1] == '=')
		return (edit_env_var(hash[0], ""), 0);
	if (!hash[1])
		return ( 0);
	if (hash[2][0] == '+')
	{
		append_env_var(hash[0], hash[1]);
	}
	else
		edit_env_var(hash[0], hash[1]);
	return (0);
}

int	ft_export(char **args)
{
	extern char	**environ;
	int			i;
	int			ret;

	ret = 0;
	if (!environ[0])
	{
		ft_putstr_fd("export: No such file or directory\n", 2);
		return (1);
	}
	if (!args[1])
		return (print_sorted_array(environ), 0);
	i = 0;
	while (args[++i])
		if (export(args[i]))
			ret = 1;
	return (ret);
}
