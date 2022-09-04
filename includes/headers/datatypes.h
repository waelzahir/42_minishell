/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:14:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/09/03 21:29:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include "minishell.h"

typedef struct s_lexer
{
	char	c;
	int		index;
	char	*source;
}	t_lexer;

typedef enum s_type
{
	arg,
	qarg,
	darg,
	redirec,
	pip,
	space,
	end,
}	t_type;

typedef struct s_token
{
	t_type	type;
	char	*def;
}	t_token;

typedef enum z_type
{
	OPERATION,
	CMD,
}	t_token_type;

typedef struct s_binary_tree
{
	void					*content;
	t_token_type			num;
	int						index;
	int						*fd;
	struct s_binary_tree	*l_child;
	struct s_binary_tree	*r_child;
}	t_btree;

typedef struct s_stack
{
	int		size;
	void	**stack;
}	t_stack;

#endif 