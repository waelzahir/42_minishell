/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:45:09 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 17:32:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}

int	push_stack(t_stack *stack, void *content)
{
	int		size;
	void	**temp;

	size = stack->size;
	if (size == 0)
	{
		stack->stack = malloc(2 * sizeof(void *));
		if (!stack->stack)
			return (1);
		stack->size++;
		stack->stack[0] = content;
		stack->stack[1] = NULL;
		return (0);
	}
	temp = malloc(sizeof(void *) * (size + 2));
	if (!temp)
		return (1);
	ft_memmove(temp, stack->stack, size * sizeof(void *));
	temp[size] = content;
	temp[size + 1] = NULL;
		stack->size++;
	free(stack->stack);
	stack->stack = temp;
	return (0);
}

void	*pop_stack(t_stack *stack)
{
	void	*ret;
	int		size;

	size = stack->size;
	if (size == 0)
		return (NULL);
	ret = stack->stack[size - 1];
	stack->stack[size - 1] = NULL;
	stack->size--;
	if (stack->size == 0)
		free(stack->stack);
	return (ret);
}

void	free_simple_stack(t_stack	*simple, char	*text)
{
	t_token	*token;

	if (text)
		printf("Syntax error near '%s'", text);
	while (simple->size)
	{
		token = pop_stack(simple);
		free(token->def);
		free(token);
	}
	free(simple);
}

void	free_nsimple_stack(t_stack	*cmd)
{
	t_token	**token;
	int		i;

	i = 0;
	while (cmd->size)
	{
		token = pop_stack(cmd);
		while (token[i])
		{
			free((*token)->def);
			free(token);
			i++;
		}
		i = 0;
	}
	free(cmd);
}
