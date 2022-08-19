/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:21:40 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/19 16:27:10 by sel-kham         ###   ########.fr       */
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

void	export_append(char *old_val, char **hash)
{
	
}

void	exec_export(char **hash, char ** env, int mode)
{
	char	*var;

	var = getenv(hash[0]);
	// if (var)
	printf("%s\n", var);
	if (mode == EXP_APPEND_MODE)
		ft_putstr_fd("Append mode\n", 1);
	if (mode == EXP_ASSIGN_MODE)
		ft_putstr_fd("Assign mode\n", 1);
}

int	ft_export(char **args)
{
	char	**hash;
	char	**tmp;
	int		i;

	if (!data.env)
	{
		ft_putstr_fd("export: No such file or directory\n", 2);
		return (1);
	}
	if (!args[1])
	{
		// print_sorted_array(data.env);
		return (0);
	}
	hash = var_to_hash(args[1]);
	if (!check_identefier(hash[0]))
	{
		ft_putstr_fd("export: Invalid identifier.\n", 2);
		return (1);
	}
	if (hash[0][ft_strlen(hash[0]) - 1] == '+')
	{
		hash[0][ft_strlen(hash[0]) - 1] = 0;
		exec_export(hash, data.env, EXP_APPEND_MODE);
	}
	else
		exec_export(hash, data.env, EXP_ASSIGN_MODE);
	return (0);
}

int main(int argc, char **argv, char **env)
{
	char **hash;
	int i;

	i = -1;
	data.env = env;
	ft_export(argv);
	return 0;
}
