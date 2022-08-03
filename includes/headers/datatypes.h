/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/03 14:44:09 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef struct  s_lexer
{
    char    *input;
    char    c;
    int    index;
} t_lexer;

typedef enum  s_num
{
    arg,
    qarg,
    darg,
    input,
    output,
    pipe,
    space,
    var,
    end,
} t_num;

typedef struct s_token
{
    t_num   type;
    char    *def; 
} t_token;

#endif