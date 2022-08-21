/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 03:56:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 19:44:50 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"

int	double_size(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
		i++;
	return (i);
}

char	**remove_pointer(char *arg, char **pointer)
{
	t_stack	*stack;
	t_stack	*temp;
	char	*poin;

	stack = ft_calloc(1, sizeof(t_stack));
	temp = ft_calloc(1, sizeof(t_stack));
	stack->stack = (void **) pointer;
	stack->size = double_size(pointer);
	while (1)
	{
		poin = pop_stack(stack);
		if (!ft_strncmp(arg, poin, ft_strlen(arg)) \
			&& poin[ft_strlen(arg)] == '=')
		{
			free(poin);
			break ;
		}
		else
			push_stack(temp, poin);
	}
	while (temp->size != 0)
		push_stack(stack, pop_stack(temp));
	return ((char **) stack->stack);
}

void	unset(char *arg)
{
	int			i;
	extern char	**environ;

	if (!environ[0])
		return ;
	i = -1;
	while (environ[++i])
		if (!ft_strncmp(arg, environ[i], ft_strlen(arg)) \
			&& environ[i][ft_strlen(arg)] == '=')
			environ = remove_pointer(arg, environ);
}

int	ft_unset(char **args)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (args[++i])
	{
		if (check_identefier(args[i]))
			unset(args[i]);
		else
		{
			ft_putstr_fd("export: Invalid identifier.\n", 2);
			ret = 1;
		}
	}
	return (ret);
}
