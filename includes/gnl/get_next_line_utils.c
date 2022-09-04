/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:04 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/29 00:28:53 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft__memcpy(void *dst, const void *src, size_t n)
{
	char	*ddst;
	char	*ssrc;
	int		i;

	if (!dst && !src)
		return (NULL);
	ddst = (char *)dst;
	ssrc = (char *)src;
	i = 0;
	while (n)
	{
		ddst[i] = ssrc[i];
		n--;
		i++;
	}
	return ((void *)(dst));
}

int	ft__strlen(char const *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft__strdup(char const *s1)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = ft__strlen(s1);
	str = malloc(((size_t)s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft__strjoin(char *s1, char const *s2)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

	j = 0;
	if (!s1)
	{	
		s1 = ft_strdup(s2);
		return (s1);
	}
	ln1 = ft__strlen(s1);
	ln2 = ft__strlen(s2);
	ss = malloc((ln1 + ln2) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft__memcpy(ss, s1, ln1);
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	free(s1);
	return (ss);
}

char	*newline(char *left)
{
	int		i;
	char	*nl;

	i = 0;
	if (!left)
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	nl = malloc((i +2) * sizeof(char));
	if (!nl)
		return (0);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		nl[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
		nl[i++] = '\n';
	nl[i] = '\0';
	return (nl);
}
