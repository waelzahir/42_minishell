/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:37 by sel-kham          #+#    #+#             */
/*   Updated: 2022/07/19 16:21:25 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

int	ft_strchrstr(char *sub, char *str)
{
	char	*pstr;

	if (sub && str)
	{
		pstr = str;
		while (*sub)
		{
			str = pstr;
			while (*str)
			{
				if (*str == *sub)
					return (1);
				str++;
			}
			sub++;
		}
	}
	return (0);
}
