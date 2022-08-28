/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:49:25 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/23 01:19:50 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	ft_pwd(int size)
{
	char	*cwd;
	
	cwd = (char *) garbage_collector(size, ALLOCATE);
	if (!getcwd(cwd, size))
	{
		if (!cwd[0])
		{
			free(cwd);
			ft_pwd(size + 1024);
		}
		printf("%s\n", cwd);
		free(cwd);
		return (0);
	}
	printf("%s\n", cwd);
	return (0);
}
