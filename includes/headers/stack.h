/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:50:51 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:35:18 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

t_stack	*init_stack(void);
int		push_stack(t_stack *stack, void *content);
void	*pop_stack(t_stack *stack);
void	free_stacked_stack(t_stack *stack);
void	free_simple_stack(t_stack *stack, char *text);
void	free_stacks(t_stack *stack, t_stack *opstack);
void	free_nsimple_stack(t_stack	*cmd);
#endif