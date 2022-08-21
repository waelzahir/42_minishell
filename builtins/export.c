/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:21:40 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 23:25:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	**var_to_hash(char *arg)
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
	char	**hash;
	int		ret;

	hash = NULL;
	ret = 0;
	hash = var_to_hash(arg);
	if (!check_identefier(hash[0]))
	{
		ft_putstr_fd("export: Invalid identifier.\n", 2);
		ret = 1;
	}
	else
	{
		if (hash[0][ft_strlen(hash[0]) - 1] == '+')
		{
			hash[0][ft_strlen(hash[0]) - 1] = 0;
			exec_export(hash, EXP_APPEND_MODE);
		}
		else
			exec_export(hash, EXP_ASSIGN_MODE);
	}
	free(hash[1]);
	free(hash[2]);
	free(hash);
	return (ret);
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
		return (ret);
	}
	i = 0;
	while (args[++i])
		ret = export(args[i]);
	return (ret);
}
