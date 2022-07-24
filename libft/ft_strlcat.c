/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:00:46 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 05:30:36 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dlen;
	size_t		slen;
	size_t		i;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize < dlen)
		return (slen + dstsize);
	while (src[i] && (dstsize - 1) > (dlen + i) && dstsize != 0)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
