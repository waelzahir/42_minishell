/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:08:33 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 05:34:31 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (needle[j] && haystack[i] && i < n)
	{
		if (haystack[i] == needle[j])
			j++;
		else if ((haystack[i] != needle[j]) && j != 0)
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (needle[j] != '\0')
		return (NULL);
	else
		return ((char *)(&haystack[i - j]));
}
