/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:34:22 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 16:44:51 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE); //TODO: ßßFREE all resources allocated here before exit()
	return (pid);
}


void	free_2d_table(char **tab)
{
	extern char **environ;
	int	i;

	i = -1;
	if (!tab)
		return ;
	if (!*tab)
	{
		free(tab);
		return ;
	}
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
