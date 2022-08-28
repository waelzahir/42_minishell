/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:17:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 16:43:05 by ozahir           ###   ########.fr       */
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
	char			*prompt;

	prompt = get_prompt();
	environ = init_env();
	if (!prompt)
		return (printf("failed to set prompt value\n"), 1);
	shell(prompt);
	free(prompt);
	return (0);
}
