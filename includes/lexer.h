/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:53:27 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/27 18:47:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
#include "minishell.h"

t_lexer *init_lex(char  *content, char  **env);
void    advance(t_lexer *lexer);
void    skip(t_lexer *lexer);
char    *char_to_str(char   c);
char    *char_append_str(char   *str, char  c);
char    *get_simple_arg(t_lexer *lexer);
char    *get_quoted_arg(t_lexer *lexer);
char    *get_dquoted_arg(t_lexer *lexer);
char    *var_expand(t_lexer *lexer);
char    *get_var_pointer(char    *key, char  **env);
char    *q_prompt(int quote);
t_token *tokenizer(t_lexer *lexer, t_tok prev);


# endif