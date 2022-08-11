/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/11 17:51:10 by ozahir           ###   ########.fr       */
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
	redirec,
	lparent,
	rparent,
	andor,
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

#endif