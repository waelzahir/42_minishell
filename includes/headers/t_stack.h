/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:11:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/10 23:22:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

t_stack	*init_stack(void);
int		push_stack(t_stack *stack, void *content);
void	*pop_stack(t_stack *stack);
void	**fill_stacks(t_stack *op, t_lexer *lexer);

#endif