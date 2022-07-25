/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:44:23 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 15:26:24 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTYPES_H
# define DTYPES_H
#include "minishell.h"

typedef enum s_tok
{
    ARG,
    PIPE,
    IN,
    OUT,
    SPAC,
    EOL,
} t_tok;

typedef struct s_token
{
    t_tok type;
    char    *content;
} t_token ;

typedef struct  s_lexer
{
    char    **env;
    char    *source;
    int     index;
    char    c;
} t_lexer;

# endif

