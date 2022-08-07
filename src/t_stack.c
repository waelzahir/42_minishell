/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:12:37 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 21:43:41 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = ft_calloc(1, sizeof(t_stack));
    if (!stack)
        return (NULL);
    return (stack);
}
int    push_stack(t_stack *stack, void    *content)
{
    int size;
    void    **temp;

    size = stack->size;
    if (size == 0)
    {
        stack->stack = malloc(2 * sizeof(void   *));
        if  (!stack->stack)
            return (1);
        stack->size++;
        stack->stack[0] = content;
        stack->stack[1] = NULL;
        return (0);
    }
    temp = malloc(sizeof(void   *) * (size + 2));
    if (!temp)
        return 1;
    ft_memmove(temp, stack->stack, size * sizeof(void *));
    temp[size] = content;
    temp[size + 1] = NULL;
     stack->size++;
    free(stack->stack);
    stack->stack = temp;
    return (0);
}
void    *pop_stack(t_stack *stack)
{
    void    *ret;
    int     size;

    size = stack->size;
    if (size == 0)
        return NULL;
    ret = stack->stack[size - 1];
    stack->stack[size - 1] = NULL;
    stack->size--;
    if (stack->size == 0)
        free(stack);
    return (ret);
}