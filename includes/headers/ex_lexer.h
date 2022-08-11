/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:36:23 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/11 18:05:11 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_LEXER_H
# define EX_LEXER_H
char    *get_string(t_lexer *lexer);
char    *expander(char  *s, char **env);
#endif