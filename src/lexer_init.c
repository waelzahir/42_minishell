/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:57:31 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 17:10:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_lexer	*init_lexer(char *source)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->source = source;
	lexer->c = source[0];
	lexer->index = 0;
	return (lexer);
}

void	lexer_advance(t_lexer *lexer)
{
	lexer->index++;
	lexer->c = (lexer->source[lexer->index]);
}

void	lexer_skip(t_lexer *lexer)
{
	while (lexer->c == ' ')
		lexer_advance(lexer);
}

char	*char_str(char c)
{
	char	*str;

	str = ft_calloc(1, 2);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

char	*char_append(char *str, char c)
{
	char	*cati;
	int		len;

	cati = NULL;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	cati = malloc(len + 2);
	if (!cati)
		return (free(str), NULL);
	ft_memcpy(cati, str, len);
	cati[len] = c;
	cati[len + 1] = '\0';
	free(str);
	return (cati);
}
