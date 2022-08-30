/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/30 16:02:40 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"
int		get_random_number()
{
	int fd;
	char	random[4];
	int 	num;
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
char	*get_random_name()
{
	char	*path;
	char	*final;
	char		*random;
	
	path = "/tmp/shell_oaoa_";
	random = ft_itoa(get_random_number());
	final = ft_strjoin(path, random);
	if (!final)
		return (free(random), NULL);
	free(random);
	return (final);
}
char	*h_clean(char	*s)
{
	char    *string;
    int i;
    
    i = 0;
    if (s[0] == 34 || s[0] == 39)
        string = s + 1;
    else
        return (s);
    while (string[i])
        i++;
    return string;
}
char	*here_doc(char	*str)
{
	char	*brk;
	char	*line;
	int		len;
	int 	fd;


	len = ft_strlen(clean_string(str + 2));
	brk = get_random_name();
	fd = open(brk, O_CREAT | O_WRONLY, 0777);
	if (fd < 0)
		return (free(str),free(brk), NULL);
	while (1)
	{
		ft_putstr_fd("here_doc>", 1);
		line = get_next_line(0);
	
		if (!line || (ft_strlen(line) - 1 == len && ft_strncmp(line, h_clean(str + 2), len) == 0))
			break ;
		line[ft_strlen(line) - 1] = 0;
		if (str[0] !=  34 && str[0] != 39)
			line = expand(line);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	if (!line)
		ft_putstr_fd("\n", 1);
	close(fd);
	free(str);
	return (brk);
}
int	apply_herdoc(char	*file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd < 0 || dup2(fd, 0) == -1)
    {
            perror("redirection");
            return (1);
    }
	close(fd);
	return (0);
	
}