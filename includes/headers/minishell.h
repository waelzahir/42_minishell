/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:50 by sel-kham          #+#    #+#             */
/*   Updated: 2022/07/01 21:47:38 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>


/*
    lexer part
*/

typedef struct s_lexer
{
    char    **envp;
    int     index;
    char    c;
    char    *source;
}   t_lexer;


t_lexer    *init_lexer(char *source, char   **envp);

void    increment_lex(t_lexer *lexer);

void    lex_white_spaces(t_lexer *lexer);


char    *get_var(t_lexer *lexer);


char  *str_append(char  *str, char  c);


char    *get_char(char  c);

int is_token(char c);

char    *var_pointer(char   *str, char  **envp);
char    *lexer_get_string(t_lexer *lexer, char  d);

/*
    token part
*/
typedef enum s_to
{
    PATH,
    ARG,
    PIPE,
    DOLLAR,
    QUOTE,
    DQUOTE,
    VAR,
    IN,
    OUT,
    SPAC,
} t_to;

typedef struct s_token
{
    t_to tok;
    char    *val;
} t_token;

t_token *get_token(int type, char   *value);
t_token *lexer_get_token(t_lexer *lexer);



#endif