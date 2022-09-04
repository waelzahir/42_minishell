/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:17:59 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

int	ft_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	if (!environ[0])
		return (0);
	while (environ[i])
	{
		if (ft_strchr(environ[i], '='))
		{
			ft_putstr_fd(environ[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
	return (0);
}
