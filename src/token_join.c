/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:46:25 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/29 23:51:37 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	tokens_free(t_token	**token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		free(token[i]->def);
		free(token[i]);
		i++;
	}
	free(token);
}

char	*collector(char *s1, char *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strjoin(s1, s2);
		return (ret);
	}
	if (!s1 && s2)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	if (s1 && !s2)
	{
		ret = ft_strdup(s1);
		return (ret);
	}
	return (NULL);
}

char	**join_cmd(t_token **tokens)
{
	char	*join;
	char	**cmd;
	t_stack	*stack;
	int		i;

	i = -1;
	stack = init_stack();
	if (!stack)
		return (NULL);
	join = NULL;
	while (tokens[++i])
	{
		if (tokens[i]->type == space && join)
		{
			push_stack(stack, join);
			join = NULL;
		}
		else
		join = collector(join, tokens[i]->def);
	}
	if (join[0] != ' ')
		push_stack(stack, join);
	cmd = (char **)stack->stack;
	free(stack);
	return (cmd);
}

char	**join_tokens(t_token **token)
{
	t_stack	*clean;
	char	**val;
	int		i;

	i = 0;
	clean = init_stack();
	if (!clean)
		return (tokens_free(token), NULL);
	while (token[i])
	{
		if (token[i]->type != redirec)
			push_stack(clean, token[i]);
		i++;
	}
	val = join_cmd((t_token **)clean->stack);
	if (!val)
		return (free_simple_stack(clean, NULL), NULL);
	free(clean->stack);
	free(clean);
	return (val);
}
