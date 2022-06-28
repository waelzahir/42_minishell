/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:50 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/24 17:02:51 by ozahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum s_to
{
    COMMAND,
    ARG,
    PIPE,
    DOLLAR,ß
    REDIRECTION,
    D_REDIRECTION,
} t_to;

typedef struct s_token
{
    t_to tok;
    char    *val;
} t_token;

typedef struct s_lexer
{
    char    **envp;
    int     index;
    char    c;
    char    *source;
}   t_lexer;

#endif