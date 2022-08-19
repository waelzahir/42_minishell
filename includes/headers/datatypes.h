/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/19 15:58:03 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef struct s_lexer
{
	char	*input;
	char	c;
	int		index;
	char	**env;
}	t_lexer;

typedef enum s_num
{
	arg,
	qarg,
	darg,
	input,
	lparent,
	rparent,
	andor,
	output,
	pip,
	space,
	var,
	end,
}	t_num;

typedef struct s_token
{
	t_num	type;
	char	*def;
}	t_token;

typedef struct s_stack
{
	int		size;
	void	**stack;
}	t_stack;

typedef enum s_atype
{
	pipeline,
	and_op,
	or_op,
	simple_comand,
}	t_atype;

typedef struct s_binary_tree
{
	void					*content;
	enum
	{
		OPERATION,
		CMD
	}	e_type;
	struct s_binary_tree	*l_child;
	struct s_binary_tree	*r_child;
}	t_btree;

typedef struct s_global_data
{
	char	**env;
	int		exit_status;
}	t_gdata;

#endif