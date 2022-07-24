/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:09:44 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 04:48:39 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	my_isspace(int c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	j;
	long	count;

	i = 0;
	j = 1;
	count = 0;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (str[i] <= '0' && str[i] >= '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (str[i] - 48) + (count * 10);
		i++;
	}
	return (count * j);
}
