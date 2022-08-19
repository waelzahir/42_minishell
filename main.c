/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:37:32 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/19 16:01:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/minishell.h"

int	exist_one(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	if (count % 2 == 1)
		return (1);
	return (0);
}

char	*q_prompt(int quote)
{
	char	*str;
	char	*prompt;

	if (quote == 39)
		prompt = "quote>";
	if (quote == 34)
		prompt = "dquote>";
	str = readline(prompt);
	if (exist_one(str, quote) == 1)
		return (str);
	while (1)
	{
		str = ft_strjoin(str, readline(prompt));
		if (exist_one(str, quote) == 1)
			break ;
	}
	return (str);
}

char	*closing_check(char *str)
{
	int	type;
	int	i;
	int	state;

	type = 0;
	i = 0;
	state = 0;
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
	str = ft_strjoin(str, q_prompt(type));
	return (str);
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

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	if (!argc && !argv)
		return (0);
	prompt = get_prompt();
	if (!prompt)
		return (0);
	data.env = envp;
	shell(prompt, envp);
}
