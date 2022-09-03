/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:51:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 15:37:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#define LEFT_NODE 0
#define RIGHT_NODE 1
#define ROOT -1

t_btree	*binary_tree_new(void *root, int type, int etat, t_stack *stack);
int	binary_tree_add_r_child(t_btree **root, t_btree *r_child);
int	binary_tree_add_l_child(t_btree **root, t_btree *l_child);
void	binary_tree_free(t_btree **root);
t_btree	*binary_tree_create(t_stack *simple_cmd, t_stack *op);

#endif