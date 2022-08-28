/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/23 15:24:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	ft_env()
{
	extern char	**environ;
	int	i;
	
	i = 0;
	if (!environ[0])
		return (0);
	while (environ[i])
	{
		ft_putstr_fd(environ[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
