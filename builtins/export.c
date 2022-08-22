/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:21:40 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/22 03:59:30 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	check_identefier(char *id)
{
	int	i;
	int	id_len;

	i = 0;
	id_len = ft_strlen(id);
	if (id[i] && (ft_isalpha(id[i]) || id[i] == '_'))
	{
		while (id[++i] && (ft_isalnum(id[i]) || id[i] == '_' || id[i] == '+'))
			if (id[i] == '+' && i != id_len - 1)
				return (0);
		if (i != id_len)
			return (0);
		return (1);
	}
	return (0);
}

void	exec_export(char **hash, int mode)
{
	extern char	**environ;

	if (hash)
		printf("") ;
	if (mode == EXP_APPEND_MODE)
		ft_putstr_fd("Append mode\n", 1);
	if (mode == EXP_ASSIGN_MODE)
		ft_putstr_fd("ASSIGN mode\n", 1);
}

int	export(char *arg)
{
	char		**hash;
	char		**env_hash;
	extern char	**environ;

	hash = arg_to_hash(arg);
	if (!check_identefier(hash[0]))
	{
		ft_putstr_fd("export: invalid identifer\n", 2);
		free_2d_table(hash);
		return (1);
	}
	env_hash = is_env_var(hash[0]);
	if (!env_hash)
	{
		environ = new_env_var(hash);
		free_2d_table(hash);
		free_2d_table(env_hash);
		return (0);
	}
	if (hash[1][ft_strlen(hash[1]) - 1] == '+')
	{
		environ = edit_env_var(hash);
		free_2d_table(hash);
		free_2d_table(env_hash);
		return (0);
	}
	unset(env_hash[0]);
	environ = new_env_var(hash);
	free_2d_table(hash);
	free_2d_table(env_hash);
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
	{
		print_sorted_array(environ);
		return (0);
	}
	i = 0;
	while (args[++i])
		ret = export(args[i]);
	return (ret);
}
