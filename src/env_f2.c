/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_f2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:03:51 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 20:06:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	memo_p(char **en, int in)
{
	static char	**input;

	if (in == 1)
	{
		free(input);
		return ;
	}
	input = en;
}

static int	is_env_var_id(char *id, char *poin)
{
	if (!ft_strncmp(id, poin, ft_strlen(id)) \
		&& (poin[ft_strlen(id)] == '=' || poin[ft_strlen(id)] == '\0'))
		return (1);
	return (0);
}

void	delete_env_var(char *id)
{
	extern char	**environ;
	t_stack		*stack;
	t_stack		*temp;
	char		*poin;

	stack = ft_calloc(1, sizeof(t_stack));
	temp = ft_calloc(1, sizeof(t_stack));
	stack->stack = (void **) environ;
	stack->size = size_counter(environ);
	while (stack->size)
	{
		poin = pop_stack(stack);
		if (is_env_var_id(id, poin))
		{
			free(poin);
			break ;
		}
		else
			push_stack(temp, poin);
	}
	while (temp->size != 0)
		push_stack(stack, pop_stack(temp));
	environ = (char **) stack->stack;
	free(stack);
	free(temp);
}
