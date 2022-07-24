/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:39:12 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 15:15:58 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*zerorule(char *s)
{
	int	i;

	s = malloc(2 * sizeof(char));
	if (!s)
	{
		return (NULL);
	}
	if (!s)
	{
		return (NULL);
	}	
	i = 0;
	s[i] = '0';
	s[i + 1] = 0;
	return (s);
}

static char	*nbr(char *s, long nbr, int i)
{
	int		a;
	int		b;
	long	c;

	a = i + 1;
	c = nbr;
	if (c < 0)
	{
		s[0] = '-';
		c *= -1;
	}
	while (c)
	{
		b = c % 10;
		c = c / 10;
		s[i] = b + 48;
		i--;
	}
	s[a] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*at;
	int		c;
	int		i;

	at = NULL;
	i = 0;
	c = n;
	if (c == 0)
		return (zerorule(at));
	while (c)
	{
		c = c / 10;
		i++;
	}
	if (n < 0)
	{
		i++;
	}
	at = malloc(i * sizeof(char) + 1);
	if (!at)
		return (NULL);
	at = nbr(at, (long)n, i - 1);
	return (at);
}
