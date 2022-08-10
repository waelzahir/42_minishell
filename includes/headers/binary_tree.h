/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:17:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/10 00:46:00 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

#include "minishell.h"

typedef struct  s_binary_tree
{
	t_stack	*content;
	t_stack	*l_child;
	t_stack	*r_child;
}	t_btree;

t_btree	*binary_tree_new(t_stack *root);
void	binary_tree_clear(t_btree **root);
int		binary_tree_add_r_child(t_btree **root, t_stack *r_child);
int		binary_tree_add_l_child(t_btree **root, t_stack *l_child);
t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op);
void	print_tree(t_stack *root);

#endif