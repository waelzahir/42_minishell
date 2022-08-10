/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:26:06 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/10 15:57:35 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_btree	*binary_tree_new(t_stack *root)
{
	t_btree	*node;

	node = (t_btree*) malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->content = root;
	node->l_child = NULL;
	node->r_child = NULL;
	return (node);
}

int	binary_tree_add_r_child(t_btree **root, t_stack *r_child)
{
	if (*root)
	{
		(*root)->r_child = r_child;
		return (0);
	}
	return (1);
}

int	binary_tree_add_l_child(t_btree **root, t_stack *l_child)
{
	if (*root)
	{
		(*root)->l_child = l_child;
		return (0);
	}
	return (1);
}

t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op)
{
	t_btree	*root;
	
	if (simple_cmd->size == 0)
		return (NULL);
	if (op->size == 0)
		return (binary_tree_new((t_stack *) pop_stack(simple_cmd)));
	root->r_child = binary_tree_create(simple_cmd, (t_stack *) pop_stack(op));
	root->l_child = binary_tree_create((t_stack *) pop_stack(simple_cmd), op);
	return (root);
}

void	print_tree(t_btree *root)
{
	static int	tab;
	if (!root)
		return ;
	while (tab-- > 0)
		printf("\t");
	printf("%s\n", root->content->stack[0]);
	printf("|__ ");
	print_tree(root->l_child);
	print_tree(root->r_child);
}
