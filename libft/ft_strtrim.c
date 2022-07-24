/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:54:16 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 15:21:38 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	cordi(char const *s1, char const *cord)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		while (cord[j])
		{
			if (s1[i] == cord[j])
				break ;
			j++;
		}
		if (cord[j] == '\0' )
			break ;
		i++;
		j = 0;
	}
	return (i);
}

static	int	rcordi(char const *s1, char const *cord, int i)
{
	int	j;
	int	a;
	int	ch;

	j = ft_strlen(cord) - 1 ;
	a = j;
	ch = i;
	i--;
	while (i != 0)
	{
		while (j != -1)
		{
			if (s1[i] == cord[j])
				break ;
			j--;
		}
		if (j == -1)
			break ;
		i--;
		j = a;
	}
	if (ch == (i + 1))
		return (ch);
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	begin = cordi(s1, set);
	end = rcordi(s1, set, i);
	str = ft_substr(s1, begin, end - begin);
	if (!str)
		return (NULL);
	return (str);
}
