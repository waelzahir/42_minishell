/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 02:21:35 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/28 23:53:32 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

int	flag_handler(char *arg)
{
	int	i;
	int	is_flag;

	i = 0;
	is_flag = 0;
	if (arg[0] != '-')
		return (is_flag);
	while (arg[++i])
	{
		if (arg[i] == 'n')
			is_flag = 1;
		else
		{
			is_flag = 0;
			break ;
		}
	}
	return (is_flag);
}

void	echo(char *arg)
{
	ft_putstr_fd(arg, 1);
	ft_putstr_fd(" ", 1);
}

int	ft_echo(char **args)
{
	int	i;
	int	is_flag;
	int	has_flag;

	i = 0;
	is_flag = 1;
	has_flag = 0;
	while (args[++i])
	{
		if (is_flag)
		{
			is_flag = flag_handler(args[i]);
			if (is_flag)
			{
				has_flag = 1;
				continue ;
			}
		}
		echo(args[i]);
	}
	ft_putchar_fd(8, 1);
	if (!has_flag)
		ft_putstr_fd("\n", 1);
	return (0);
}
