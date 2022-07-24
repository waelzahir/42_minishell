/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:22:31 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/17 05:32:32 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapi;

	i = 0;
	if (!s)
		return (NULL);
	mapi = ft_strdup(s);
	if (!mapi)
		return (NULL);
	while (mapi[i])
	{
		mapi[i] = (*f)(i, mapi[i]);
		i++;
	}
	return (mapi);
}
