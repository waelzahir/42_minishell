/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:33:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/04 20:50:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

static void	print(char *g[], int a)
{
	int	i;

	i = -1;
	while (++i < a)
	{
		if (g[i][0])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(g[i], 1);
			write(1, "\n", 1);
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_sorted_array(char **argv)
{
	char	*p;
	int		i;
	int		k;
	int		size;

	size = size_counter(argv);
	if (size == -1)
		return ;
	i = -1;
	k = 0;
	while (++i < size - 1)
	{
		k = i;
		while (++k < size)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
			{
				p = argv[i];
				argv[i] = argv[k];
				argv[k] = p ;
			}
		}
	}
	print(argv, size);
}

static int	get_equal(char *arg)
{
	int	i;

	i = 0;
	while (arg[i++])
	{
		if (arg[i] == '=')
		{
			return (i);
		}
	}
	return (-1);
}

char	**arg_to_hash(char *arg)
{
	int		i;
	char	**hash;

	hash = (char **) malloc(sizeof(char *) * 4);
	if (!hash)
		exit (EXIT_FAILURE);
	i = get_equal(arg);
	if (i == -1)
		i = ft_strlen(arg);
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
