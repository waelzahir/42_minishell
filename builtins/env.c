/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:54:31 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/16 16:04:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	ft_env(char **env)
{
	if (!env)
		return (0);
	while (*env)
	{
		ft_putstr_fd(*env, 1);
		ft_putstr_fd("\n", 1);
		env++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	if (!argc || !argv)
		return (1);
	ft_env(env);
	return (0);
}