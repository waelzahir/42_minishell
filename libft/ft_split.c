/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:06:00 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/20 16:38:21 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	**freed(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (NULL);
}

static	int	rows(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	j++;
	return (j);
}

static	char	**alocation(char **spl, const char *s, char c)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i + j] && s[i + j] != c)
			j++;
		spl[a] = malloc(j * sizeof(char) + 1);
		if (!spl[a])
			return (freed(spl));
		i = i + j;
		j = 0;
		a++;
	}
	spl[a] = NULL;
	return (spl);
}

static	char	**endl(char **spl, const char *s, char c)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0' )
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i + j] && s[j + i] != c)
			j++;
		ft_strlcpy(spl[a], s + i, j + 1);
		i = i + j;
		j = 0;
		a++;
	}
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	char	**spl;

	if (!s)
		return (NULL);
	a = rows(s, c);
	if (a == 0)
		return (NULL);
	spl = malloc(a * sizeof(char *));
	if (!spl)
		return (NULL);
	spl = alocation(spl, s, c);
	if (spl == NULL)
		return (NULL);
	spl = endl(spl, s, c);
	return (spl);
}
