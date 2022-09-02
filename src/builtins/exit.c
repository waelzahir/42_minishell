/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:24 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/02 20:08:49 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

static int	is_number(char *s)
{
	int	i;

 	i = -1;
	while (s[++i])
  		if (!ft_isdigit(s[i]))
		  return (1);
	return (0);
}

void	ft_exit(char **arg)
{
	int	s;

	if (!arg)
		exit(0);
	if (!arg[1])
		exit(0);
	if (!is_number(arg[1]))
	{
		s = ft_atoi(arg[1]);
		exit(s);
	}
 	ft_putstr_fd("Numeric argument required\n", 2);
	exit(255);
}
