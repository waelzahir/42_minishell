/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:08:03 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/13 17:04:27 by ozahir           ###   ########.fr       */
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
int filerules(char	c)
{
	if (c == '<' || c == '>' || c == '\0' || c == '|' || c == ' ')
		return (1);
	return (0); 
}
char	*get_filename(t_lexer *lexer)
{
	char	*file;

	file = NULL;
	if(lexer->c == 39)
		return (get_argq(lexer));
	else if (lexer->c == 34)
		return (get_argd(lexer));
	if (filerules(lexer->c) == 1)
		return (NULL);
	file = char_to_str(lexer->c);
	advance(lexer);
	while (!filerules(lexer->c))
	{
		file = char_append(file, lexer->c);
		if (!file)
				return (NULL);
		advance(lexer);
	}
	return (file);
}
char	*get_red(t_lexer *lexer, char type)
{
	char	*str_to;
	char	*str_f;

	str_f  = NULL;
	str_to = NULL;
	str_to = char_to_str(lexer->c);
	advance(lexer);
	while (lexer->c == type)
	{
		str_to = char_append(str_to, type);
		if (!str_to)
			return (NULL);
		advance(lexer);
	}
	if (ft_strlen(str_to) > 2)
		return (ft_putstr_fd("parse error near: ", 1), write(1,&str_to[2],1), NULL);
	skip_ws(lexer);
	str_f = get_filename(lexer);
	if (!str_f)
		return (ft_putstr_fd("parse error near: ", 1), write(1,&lexer->c,1), NULL)	;
	return str_to;
}
