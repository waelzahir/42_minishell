/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:49:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:41:54 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

t_lexer	*init_lexer(char *line);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip(t_lexer *lexer);
char	*char_str(char c);
char	*char_append(char *str, char c);
int		is_token(char c);
char	*get_argn(t_lexer *lexer);
char	*get_argq(t_lexer *lexer);
char	*get_argd(t_lexer *lexer);
char	*get_pipe(t_lexer *lexer);
t_token	*set_token(int type, char *content);
t_token	*lexer_get_token(t_lexer *lexer);
char	*get_red(t_lexer *lexer, char type);

#endif