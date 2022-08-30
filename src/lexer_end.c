/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:13:43 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/30 16:44:48 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_token	*set_token(int type, char *content)
{
	t_token	*token;

	if (!content)
		return (NULL);
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (printf("malloc!"), free(content), NULL);
	token->type = type;
	token->def = content;
	return (token);
}
int	sfilerules(char c)
{
	if (c == '\0' || c == '|' || c == ' ')
		return (1);
	return (0);
}
int	filerules(char c)
{
	if (c == '<' || c == '>' || c == '\0' || c == '|' || c == ' ')
		return (1);
	return (0);
}

char	*filerror(int i, char *str, t_lexer *lexer)
{
	if (!i && ft_strlen(str) > 2)
	{
		printf("syntax error near '%c'\n", str[0]);
		return (NULL);
	}
	if (!i && ft_strlen(str) > 2 && lexer->c == '\0')
	{
		printf("syntax error near '\\n'\n");
		return (NULL);
	}
	printf("syntax error near '%c'\n", str[ft_strlen(str) - 1]);
	return (NULL);
}

char	*get_red_file(char *str, t_lexer *lexer)
{
	char	*file;
	size_t	len;

	len = ft_strlen(str);
	if (len > 2 || filerules(lexer->c))
		return (filerror(0, str, lexer));
	file = str;
	while (!sfilerules(lexer->c))
	{		
		file = char_append(file, lexer->c);
		if (!file)
			return (NULL);
		lexer_advance(lexer);
	}
	if (ft_strlen(file) <= len)
		return (filerror(1, str, lexer));
	if (len == 2 && file[0] == '<')
		return (here_doc(file));
	return (file);
}

char	*get_red(t_lexer *lexer, char type)
{
	char	*str;

	str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (lexer->c == type)
	{
		str = char_append(str, type);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	lexer_skip(lexer);
	str = get_red_file(str, lexer);
	lexer_skip(lexer);
	return (str);
}
