/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:14:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/23 17:03:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

#include "minishell.h"

typedef struct s_lexer
{
    char    c;
    int     index;
    char    *source;
} t_lexer;

typedef enum 
{
    arg,
	qarg,
	darg,
	redirec,
	pip,
	space,
	end,
}   t_type;

typedef struct  s_token
{
    t_type  type;
    char    *def;
}   t_token;

typedef	enum s_type
{
	OPERATION,
	CMD,
}	token_type;

typedef struct s_binary_tree
{
	void					*content;
 	token_type			num;
	int					index;
	int					*fd;
	struct s_binary_tree	*l_child;
	struct s_binary_tree	*r_child;
}	t_btree;

typedef struct s_stack
{
	int		size;
	void	**stack;
}	t_stack;


#endif 