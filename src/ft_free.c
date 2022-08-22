/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 03:27:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/22 03:28:37 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	free_2d_table(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}
