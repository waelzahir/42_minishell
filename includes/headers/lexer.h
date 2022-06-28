/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:05:44 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/28 21:37:43 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

t_lexer *init_lexer(char    *source);



void    increment_lex(t_lexer *lexer);



void    lex_white_spaces(t_lexer  *lexer);



char    *get_char(char  *c);


t_token *get_char_token(t_lexer *lexer);



char    *get_str_dquote(t_lexer *lexer);


char    *get_str_quote(t_lexer *lexer);


char    *get_var(t_lexer *lexer);


char  *str_append(char  *str, char  c);







t_token *lexer(t_lexer *lexer);
#endif