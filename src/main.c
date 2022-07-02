/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/07/02 19:13:53 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	main(void)
{
	char	*cmd;

	while (true)
	{
		cmd = readline("Minishell $ ");
	}
	free_all((void *) cmd);
	return (0);
}
