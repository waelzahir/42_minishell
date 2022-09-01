/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/01 17:09:14 by sel-kham         ###   ########.fr       */
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
	string[i - 1] = 0;
	return string;
}
char	*get_n_file()
{
	char	*file;
	int		i;

	i = 0;
	file = get_random_name();
	if (!file)
		return (NULL);
	while (access(file, F_OK) == 0 && i != 5)
	{
		free(file);
		file = get_random_name();
		if (!file)
			return (NULL);
		i++;
	}
	if (i == 5)
	{
		free(file);
		return (NULL);
	}
	return (file);
}

int	get_here_docf(int	*pid, char	*brkline, int	exp)
{
	char	*line;
	size_t len;

	len = ft_strlen(brkline);
	if (!pid[0])
		deflt_signal();
	while(1 && pid[0] == 0)
	{
		line = readline("> ");
		if (!line)
			return (close(pid[1]), exit(0), 0);
		if (ft_strlen(line)  == len && ft_strncmp(line, brkline, len) == 0)
		{
			return (free(line), close(pid[1]), exit(0), 0);
			
		}
		if (exp == 0)
		{
			line = expand(line);
		}
		ft_putstr_fd(line, pid[1]);
		ft_putstr_fd("\n", pid[1]);

		free(line);
	}
	return (0);
}

char	*here_doc(char	*str)
{
	char	*filename;
	char	*breakline;
	int		pid[3];
	int		expand;


	expand = 0;
	if (str[2] == 34 || str[2] == 39)
		{
			breakline = h_clean(str + 2); 
			expand = 1;
		} 
	else
		breakline = str + 2;
	filename = get_n_file();
	if (!filename)
		return (free(str), NULL);
	pid[1] = open(filename, O_CREAT | O_WRONLY, 0777);
	if (pid[1] < 0)
		return (perror("here doc"), NULL);
	// rl_catch_signals = 1;
	pid[0] = ft_fork();
	if (pid[0])
		ignore_signal();
	get_here_docf(pid, breakline, expand);
	waitpid(pid[0], &exit_stat[0], 0);
	// ft_putstr_fd("here_doc>  \n", 2);
	rl_catch_signals = 0;
	signals_handler();
	// ft_putstr_fd("\b\b  ", 1);
	close(pid[1]);
	free(str);
	return (filename);
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