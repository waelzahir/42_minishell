/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 21:04:54 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	*h_clean(char *s)
{
	char	*string;
	int		i;

	i = 0;
	if (s[0] == 34 || s[0] == 39)
		string = s + 1;
	else
		return (s);
	while (string[i])
		i++;
	string[i - 1] = 0;
	return (string);
}

char	*get_n_file(void)
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

int	get_here_docf(int *pid, char *brkline, int exp)
{
	char	*line;
	size_t	len;

	len = ft_strlen(brkline);
	if (!pid[0])
		signal(SIGINT, handl);
	while (1 && pid[0] == 0)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
			return (close(pid[1]), exit(0), 0);
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) == len && ft_strncmp(line, brkline, len) == 0)
			return (free(line), close(pid[1]), exit(0), 0);
		if (exp == 0)
			line = expand(line);
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
	breakline = get_break_line(str, &expand);
	filename = get_n_file();
	if (!filename)
		return (free(str), NULL);
	pid[1] = open(filename, O_CREAT | O_WRONLY, 0777);
	if (pid[1] < 0)
		return (perror("here doc"), NULL);
	pid[0] = ft_fork();
	if (pid[0])
		ignore_signal();
	get_here_docf(pid, breakline, expand);
	waitpid(pid[0], &g_exit_stat[0], 0);
	rl_catch_signals = 0;
	signals_handler();
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
