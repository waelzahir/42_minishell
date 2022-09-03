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
	exit_stat[3] = 1;
	if (!prompt)
		return (printf("failed to set prompt value\n"), 1);
	shell(prompt);
	free(prompt);
	clear_history();
	free_2d_table(environ);
	memo_p(NULL, 1);
	return (0);
}
