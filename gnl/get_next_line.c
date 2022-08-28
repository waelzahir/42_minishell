/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:13 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 22:47:47 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_sig(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*bufferfill(int fd, char *temp)
{
	char	*buffer;
	int		total;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	total = 1;
	while (total != 0 && !nl_sig(temp))
	{
		total = read(fd, buffer, BUFFER_SIZE);
		if (total == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[total] = 0;
		temp = ft__strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*rest(char *str)
{
	int		i;
	int		l;
	char	*tmp;

	l = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	tmp = malloc(sizeof(char) * (ft__strlen(str) - i + 1));
	i++;
	while (str[i] != '\0')
	tmp[l++] = str[i++];
	tmp[l] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*garb;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	garb = bufferfill(fd, garb);
	if (!garb)
		return (NULL);
	str = newline(garb);
	garb = rest(garb);
	if (str[0] == '\0')
	{
		free(garb);
		free(str);
		return (NULL);
	}
	return (str);
}
