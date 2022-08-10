/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:08:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/10 23:05:49 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	*get_argq(t_lexer *lexer)
{
	char	*str;

	advance(lexer);
	if (lexer->c == 39)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (advance(lexer), str);
	}
	str = char_to_str(lexer->c);
	if (!str)
		return (NULL);
	advance(lexer);
	while (lexer->c != 39)
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		advance(lexer);
	}
	advance(lexer);
	return (str);
}

char	*get_var(t_lexer *lexer)
{
	char	*str;

	str = NULL;
	advance(lexer);
	if (lexer->c == '$')
	{
		str = char_to_str('1');
		if (!str)
			return (NULL);
		return (advance(lexer), str);
	}
	if (lexer->c == '?')
	{
		str = ft_strdup("blati, azebi");
		if (!str)
			return (NULL);
		return (advance(lexer), str);
	}
	return (get_var_extend(lexer));
}

char	*get_var_extend(t_lexer	*lexer)
{
	char	*str;

	str = NULL;
	if (is_token(lexer->c))
	{
		str = char_to_str('$');
		if (!str)
			return (NULL);
		return (str);
	}
	str = char_to_str(lexer->c);
	if (!str)
		return (NULL);
	advance(lexer);
	while (!is_token(lexer->c))
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		advance(lexer);
	}
	str = extend_var(str, lexer->env);
	return (str);
}

char	*get_red(t_lexer *lexer, char type)
{
	char	*str;

	str = char_to_str(type);
	if (!str)
		return (NULL);
	advance(lexer);
	while (lexer->c == type)
	{
		str = char_append(str, type);
		if (!str)
			return (NULL);
		advance(lexer);
	}
	skip_ws(lexer);
	if (lexer->c == 34)
		return (ft_strjoin(str, get_argd(lexer)));
	else if (lexer->c == 39)
		return (ft_strjoin(str, get_argq(lexer)));
	return (ft_strjoin(str, get_argn(lexer)));
}
