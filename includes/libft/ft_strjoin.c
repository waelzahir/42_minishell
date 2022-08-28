/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:15:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 19:44:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strjoin(char *s1, char  *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, s1_len);
	while (++i < s2_len)
		result[i + s1_len] = s2[i];
	result[s1_len + s2_len] = '\0';
	return (result);
}
