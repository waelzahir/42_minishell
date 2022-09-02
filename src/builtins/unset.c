/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 03:56:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/02 20:59:17 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minishell.h"

int	size_counter(char **pointer)
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
	stack->size = size_counter(pointer);
	while (1)
	{
		poin = pop_stack(stack);
		if (!ft_strncmp(arg, poin, ft_strlen(arg)) \
			&& poin[ft_strlen(arg)] == '=')
		{
			// free(poin);
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
	char	*env;

	env = get_env_var(arg);
	if (env)
		delete_env_var(arg);
}

int	ft_unset(char **args)
{
	int			i;
	int			ret;
	extern char	**environ;

	i = 0;
	ret = 0;
	if (!environ)
		return (1);
	if (!environ[0])
	{
		ft_putstr_fd("Unset: Invalid file.\n", 2);
		return (1);
	}
	while (args[++i])
	{
		if (check_identefier(args[i]))
			unset(args[i]);
		else
		{
			ft_putstr_fd("Unset: Invalid identifier.\n", 2);
			ret = 1;
		}
	}
	return (ret);
}
