/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/07 19:58:39 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

t_lexer *lexer_init(char *input, char   **env);
int     is_token(char   c);
void    advance(t_lexer    *lexer);
void    skip_ws(t_lexer *lexer);
char    *char_to_str(char   c);
char    *char_append(char   *str, char  c);
char    *get_argn(t_lexer    *lexer);
char    *get_argq(t_lexer   *lexer);
char    *get_argd(t_lexer   *lexer);
char    *get_var(t_lexer *lexer);
char    *get_var_extend(t_lexer *lexer);
char    *extend_var(char    *s, char    **env);
char    *get_red(t_lexer  *lexer, char   type);
char    *get_pipe(t_lexer   *lexer);
#endif