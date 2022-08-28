/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:02:52 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/28 21:20:29 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_token	*lexer_get_token(t_lexer *lexer)
{
	if (lexer->index == 0)
		lexer_skip(lexer);
	if (lexer->c == '\0')
		return (set_token(end, ft_calloc(1, 1)));
	if (lexer->c == ' ')
		return (lexer_skip(lexer), set_token(space, char_str(' ')));
	if (lexer->c == 34)
		return (set_token(darg, get_argd(lexer)));
	if (lexer->c == 39)
		return (set_token(qarg, get_argq(lexer)));
	if (lexer->c == '|')
		return (set_token(pip, get_pipe(lexer)));
	if (lexer->c == '<')
		return (set_token(redirec, get_red(lexer, '<')));
	if (lexer->c == '>')
		return (set_token(redirec, get_red(lexer, '>')));
	return (set_token(arg, get_argn(lexer)));
}

void	fill_lesser(t_stack	*stack_op, t_stack *stack_cmd,
	t_token *token, t_stack *stack)
{
	push_stack(stack_cmd, stack->stack);
	stack->size == 0;
	push_stack(stack_op, token);
}

void	free_stacks(t_stack	*cmd, t_stack	*op)
{
	free_simple_stack(op, NULL);
	free_nsimple_stack(cmd);
}

int	fill_stacks(t_stack *stack_cmd, t_stack *stack_op, t_lexer *lexer)
{
	t_token	*token;
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (0);
	while (lexer->c != '0')
	{
		token = lexer_get_token(lexer);
		if (!token)
			return (free_simple_stack(stack, NULL), 1);
		if (token->type != pip)
			push_stack(stack_cmd, token);
		else if (token->type == pip && stack->size)
			fill_lesser(stack_op, stack_cmd, token, stack);
		else
			return (free_simple_stack(stack, "|"), 1);
	}
	if (stack->size)
		push_stack(stack_cmd, stack->stack);
	stack->size = 0;
	if (stack_cmd->size <= stack_op->size)
		return (free_simple_stack(stack, "|"), 1);
	return (free_simple_stack(stack, NULL), 0);
}

t_btree	*parser(char *str)
{
	t_stack	*cmd_stack;
	t_stack	*op_stack;
	t_lexer	*lexer;

	lexer = init_lexer(str);
	if (!lexer)
		return (NULL);
	cmd_stack = init_stack();
	if (!cmd_stack)
	{
		free(lexer);
		return (NULL);
	}
	op_stack = init_stack();
	if (!op_stack)
	{
		free(cmd_stack);
		free(lexer);
		return (NULL);
	}
	if (fill_stacks(cmd_stack, op_stack, lexer) == 1)
		return (free(lexer), free_stacks(cmd_stack, op_stack), NULL);
	return (free(lexer), binary_tree_create(cmd_stack, op_stack));
}
