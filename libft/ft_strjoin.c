/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:28:19 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/26 21:06:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
char	*ft_strjoin(char  *s1, char const *s2)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (s1);
	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	ss = malloc((ln1 + ln2) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s1, ln1);
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	return (ss);
}
