/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 21:04:54 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	get_random_number(void)
{
	int		fd;
	char	random[4];
	int		num;

	fd = open("/dev/urandom", O_RDONLY, 0777);
	if (fd < 0)
		return (-1);
	if (read(fd, random, 3) == -1)
		return (close(fd), -1);
	num = random[0] * random[1] * random[2];
	num = num * 10 + 1000;
	close(fd);
	return (num);
}

char	*get_random_name(void)
{
	char	*path;
	char	*final;
	char	*random;

	path = "/tmp/shell_oaoa_";
	random = ft_itoa(get_random_number());
	final = ft_strjoin(path, random);
	if (!final)
		return (free(random), NULL);
	free(random);
	return (final);
}

char	*get_break_line(char	*str, int *expand)
{
	if (str[2] == 34 || str[2] == 39)
	{
		*expand = 1;
		return (h_clean(str + 2));
	}
	else
		return (str + 2);
}
