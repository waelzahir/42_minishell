/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 03:56:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 16:29:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minishell.h"


int	double_size(char **pointer)
{
	int i;
	i = 0;
	while (pointer[i])
	i++;
	return (i);
}

char **remove_pointer(char	*arg, char	**pointer)
{
	t_stack *stack;
	t_stack *temp;
	char	*poin;
	
	stack = ft_calloc(1, sizeof(t_stack));
	temp = ft_calloc(1 , sizeof(t_stack));
	stack->stack = (void **) pointer;
	stack->size = double_size(pointer);
	
	while (1)
	{
		poin = pop_stack(stack);
		if (!ft_strncmp(arg, poin, ft_strlen(arg)) && poin[ft_strlen(arg)] == '=')
			{
				poin = NULL;
				break ;
			}
		else	push_stack(temp, poin);		
	}
	while (temp->size!= 0)
		push_stack(stack, pop_stack(temp));
	return ((char **) stack->stack);
}

void unset(char 	*arg)
{
	int i;
	extern char **environ;

	if (!environ[0])
		return ;
	i = -1;
	while (environ[++i])
		if (!ft_strncmp(arg, environ[i], ft_strlen(arg)) && environ[i][ft_strlen(arg)] == '=')
			environ = remove_pointer(arg, environ);
}


void	ft_unset(char	**args)
{
	int i;

	i = 1;
	while (args[i])
	{
		unset(args[i]);
		i++;
	}
}


int main(int argc, char **argv)
{
	if (!argc)
		printf("zbi!");
	system("export ZBI=XXX");
	ft_unset(argv);
	system("env");
	return (0);
}





// void	remove_var(char *id)
// {
// 	extern char	**environ;
// 	char		*var;
// 	int			i;
// 	int			j;

// 	i = -1;
// 	while (environ[++i])
// 	{
// 		j = -1;
// 		while (environ[i] && environ[i][++j] != '=')
// 			;
// 		var = ft_substr(environ[i], 0, j);
// 		if (!ft_strncmp(id, var, ft_strlen(var)))
// 	}
		
// }

// int	ft_unset(char **args)
// {
// 	extern char	**environ;
// 	char		**hash;
// 	char		*var;
// 	int			i;

// 	i = -1;
// 	hash = var_to_hash(args);
// 	if (!hash)
// 		exit(EXIT_FAILURE);
// 	var = getenv(hash[0]);
// 	if (!var)
// 	{
// 		free(hash[0]);
// 		free(hash[1]);
// 		free(hash);
// 		free(var);
// 		return (0);
// 	}
// 	while ()
// }
