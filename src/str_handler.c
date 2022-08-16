/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:49:46 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/16 17:50:02 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

static void    print(char g[], int a)
{
	int    i;

	i = -1;
	while (++i < a)
	{
		ft_putstr(g[i]);
		write(1, "\n", 1);
	}
}

static int	size_counter(char **args)
{
	int	i;

	i = -1;
	if (!args)
		return (-1);
	while (args[++i])
		;
	return (i);
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
	while (++i <= size - 1)
	{
		k = i;
		while (++k <= size)
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
