/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:29:14 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/08 16:23:46 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_token *tokenizer(t_lexer *lexer);
t_token *set_token(int  type, char  *content);
int is_alpha(char   c);
void    parser(char *str, char  **env);


# endif