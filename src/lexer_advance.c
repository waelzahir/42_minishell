/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_advance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:06:09 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 17:09:08 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	is_token(char c)
{
	if (c == 39 || c == 34 || c == '|'
		|| c == '>' || c == '<' || c == ' ' || c == '\0')
		return (1);
	return (0);
}

char	*get_argn(t_lexer *lexer)
{
	char	*str;

	str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (!is_token(lexer->c))
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	return (str);
}

char	*get_argq(t_lexer *lexer)
{
	char	*str;

	lexer_advance(lexer);
	if (lexer->c == 39)
		return (lexer_advance(lexer), ft_calloc(1, 1));
	str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (lexer->c != 39)
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return (str);
}

char	*get_argd(t_lexer *lexer)
{
	char	*str;

	lexer_advance(lexer);
	if (lexer->c == 34)
		return (lexer_advance(lexer), ft_calloc(1, 1));
		str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (lexer->c != 34)
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return (str);
}

char	*get_pipe(t_lexer *lexer)
{
	char	*str;

	str = ft_calloc(1, 2);
	if (!str)
		return (NULL);
	str[0] = '|';
	lexer_advance(lexer);
	lexer_skip(lexer);
	return (str);
}
