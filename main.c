/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:17:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 19:04:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/minishell.h"

int	closing_check(char *str, int *fd)
{
	int	type;
	int	i;
	int	state;

	type = 0;
	i = 0;
	state = 0;
	fd[0] = -1;
	fd[1] = -1;
	while (str[i])
	{
		if ((str[i] == 39 || str[i] == 34) && state == 0)
		{
			state = 1;
			type = str[i];
			i++;
		}
		if (str[i] == type && state == 1)
			state = 0;
		i++;
	}
	if (state)
		return (printf("error: unclosed quotes\n"), 1);
	return (0);
}

char	*get_prompt(void)
{
	char	*user;
	char	*prompt;

	user = getenv("USER");
	if (!user)
		prompt = ft_strdup("trial@shell % ");
	else
		prompt = ft_strjoin(user, "@shell % ");
	if (!prompt)
		return (NULL);
	return (prompt);
}

int	main(void)
{
	char		*prompt;
	extern char	**environ;

	prompt = get_prompt();
	init_env();
	g_exit_stat[3] = 1;
	if (!prompt)
		return (printf("failed to set prompt value\n"), 1);
	shell(prompt);
	ft_putstr_fd("\b\b  \b\b", 2);
	free(prompt);
	clear_history();
	free_2d_table(environ);
	memo_p(NULL, 1);
	return (0);
}
