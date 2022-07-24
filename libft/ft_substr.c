/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:22:01 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 15:17:13 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*zerorule(char *ss)
{
	ss[0] = 0;
	return (ss);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;
	unsigned int	sl;

	i = 0;
	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (len > sl)
		len = sl;
	ss = malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	if (start > sl)
		return (zerorule(ss));
	while (s[start] && i < len)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = 0;
	return (ss);
}
