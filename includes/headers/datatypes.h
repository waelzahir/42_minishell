/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 20:14:01 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef struct  s_lexer
{
    char    *input;
    char    c;
    int    index;
    char    **env;
} t_lexer;

typedef enum  s_num
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
} t_num;

typedef struct s_token
{
    t_num   type;
    char    *def; 
} t_token;

typedef struct s_stack
{
    int size;
    void    **stack;
} t_stack;

#endif