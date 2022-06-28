/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:05:44 by ozahir            #+#    #+#             */
/*   Updated: 2022/06/28 19:11:08 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

t_lexer *init_lexer(char    *source);
void    increment_lex(t_lexer *lexer);
void    avoid_white_spaces(t_lexer  *lexer);


t_token *lexer(t_lexer *lexer);
#endif