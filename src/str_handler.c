/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:33:20 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/29 00:33:43 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

static void    print(char *g[], int a)
{
	int    i;

	i = -1;
	while (++i < a)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(g[i], 1);
		write(1, "\n", 1);
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
