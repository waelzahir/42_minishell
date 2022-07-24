/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:14:17 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 05:12:58 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ddst;
	char	*ssrc;

	ssrc = (char *)src;
	ddst = (char *)dst;
	i = 0;
	if (ssrc == ddst)
		return (dst);
	else if (ssrc < ddst)
	{
		while (len--)
			ddst[len] = ssrc[len];
	}
	else
	{
		while (src && len != i)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	return (dst);
}
