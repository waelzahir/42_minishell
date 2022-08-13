/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:12:37 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/13 16:38:13 by ozahir           ###   ########.fr       */
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
		free(stack);
	return (ret);
}

void	**fill_stacks(t_stack *op, t_lexer *lexer)
{
	t_token	*token;
	t_stack	*simple_cmd;
	void	**s_stack;

	simple_cmd = init_stack();
	if (!simple_cmd)
		return (NULL);
	token = tokenizer(lexer);
	if (token->type == pip)
		return (printf("pipe error\n"), NULL);
	while (token && token->type != end && token->type != pip)
	{
		push_stack(simple_cmd, token);
		token = tokenizer(lexer);
		if (token && token->def == NULL)
			return (NULL);
		if (token->type == pip)
			break ;
	}
	if (token->type == pip && lexer->c == '\0')
		return (printf("pipe error\n"), NULL);
	else if	(token->type == pip)
		push_stack(op, token);
		
	s_stack = simple_cmd->stack;
	free(simple_cmd);
	return (s_stack);
}
