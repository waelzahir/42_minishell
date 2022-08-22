/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:18:42 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/22 23:44:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

void	*garbage_collector(int size, int choice)
{
	static t_stack	*stack;
	void			*pointer;
	int				res;

	if (choice == ALLOCATE)
	{
		if (!stack)
		{
			stack = init_stack();
			if (!stack)
				exit(EXIT_FAILURE);
		}
		pointer = malloc(size);
		if (!pointer)
			garbage_collector(size, FREE);
		res = push_stack(stack, pointer);
	}
	else if (choice == FREE)
	{
		while (stack->size)
			free(pop_stack(stack));
		exit(EXIT_FAILURE);
	}
	return (pointer);
}
