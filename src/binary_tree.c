/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:05:21 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 16:54:55 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_btree	*binary_tree_new(void *root, int type, int etat, t_stack *stack)
{
	t_btree		*node;
	static int	index;

	if (etat == 1)
		return (ft_bzero(&index, 4), NULL);
	node = (t_btree *) malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->content = root;
	node->num = type;
	if (type == CMD)
	{
		node->index = index;
		index++;
	}
	else
		node->index = -1;
	node->l_child = NULL;
	node->r_child = NULL;
	if (!stack->size)
		free(stack);
	return (node);
}

int	binary_tree_add_r_child(t_btree **root, t_btree *r_child)
{
	if (*root)
	{
		(*root)->r_child = r_child;
		return (0);
	}
	return (1);
}

int	binary_tree_add_l_child(t_btree **root, t_btree *l_child)
{
	if (*root)
	{
		(*root)->l_child = l_child;
		return (0);
	}
	return (1);
}

void	binary_tree_free(t_btree **root)
{
	t_token	*token;
	if (!root)
		return ;
	if (!*root)
		return ;
	binary_tree_free(&((*root)->l_child));
	binary_tree_free(&((*root)->r_child));
	if ((*root)->num == CMD)
	{
		
		tokens_free((*root)->content);
	}
	if ((*root)->num == OPERATION)
	{
		token = (t_token *) (*root)->content;
		free(token->def);
		free(token);
	}
	free(*root);
}

t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op)
{
	t_btree	*node;

	if (!simple_cmd->size)
		return (NULL);
	if (!op->size)
		return (binary_tree_new(pop_stack(simple_cmd), CMD, 0, simple_cmd));
	node = binary_tree_new(pop_stack(op), OPERATION, 0, op);
	if (!node)
		return (NULL);
	node->r_child = binary_tree_create(simple_cmd, op);
	node->l_child = binary_tree_create(simple_cmd, op);
	return (node);
}
