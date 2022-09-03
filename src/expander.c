/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:29:15 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 20:18:07 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

char	*expantion(char *str, char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strlen(str) < ft_strlen(environ[i])
			&& !ft_strncmp(str, environ[i], ft_strlen(str))
			&& environ[i][ft_strlen(str)] == '=')
			return (ft_strdup(&environ[i][ft_strlen(str)] + 1));
			i++;
	}
	return (ft_calloc(1, 1));
}

char	*get_var(t_lexer *lexer, char **environ)
{
	char	*str;

	str = NULL;
	lexer_advance(lexer);
	if (lexer->c == '$')
		return (lexer_advance(lexer), ft_strdup("ma3arefch "));
	if (lexer->c == '?')
		return (lexer_advance(lexer), ft_strdup(ft_itoa(g_exit_stat[3])));
	if (lexer->c == '\0')
		return (char_str('$'));
	str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (!is_token(lexer->c) && lexer->c != '$')
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	str = expantion(str, environ);
	return (str);
}

char	*get_string(t_lexer *lexer, char **environ)
{
	char	*str;

	str = NULL;
	if (lexer->c == '$')
		return (get_var(lexer, environ));
	str = char_str(lexer->c);
	if (!str)
		return (NULL);
	lexer_advance(lexer);
	while (lexer->c != '\0' && lexer->c != '$')
	{
		str = char_append(str, lexer->c);
		if (!str)
			return (NULL);
		lexer_advance(lexer);
	}
	return (str);
}

char	*expand(char *s)
{
	t_lexer		*lexer;
	char		*ret;
	char		*str;
	extern char	**environ;

	ret = NULL;
	str = NULL;
	if (s[0] == '\0')
		return (ft_calloc(1, 1));
	lexer = init_lexer(s);
	if (!lexer)
		return (NULL);
	while (lexer->c != '\0')
	{
		str = get_string(lexer, environ);
		if (!str)
			return (free(lexer), NULL);
		ret = ft__strjoin(ret, str);
		if (!ret)
			return (NULL);
		free(str);
	}
	free(lexer);
	free(s);
	return (ret);
}

void	expander(t_token **token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i]->type == arg || token[i]->type == darg)
			token[i]->def = expand(token[i]->def);
		i++;
	}
}
