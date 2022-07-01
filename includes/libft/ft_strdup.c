/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:34:08 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/30 19:51:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	i;
	size_t	target_len;

	i = -1;
	if (!s1)
		return (NULL);
	target_len = ft_strlen(s1) + 1;
	target = (char *) malloc(target_len * sizeof(char));
	if (!target)
		return (0);
	ft_memcpy(target, s1, target_len);
	return (target);
}
