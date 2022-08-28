/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:51:53 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/28 23:52:03 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
#define EXPANDER_H

void    expander(t_token   **token);
char    *expand(char  *s);
char    *get_string(t_lexer *lexer, char    **environ);
char	*get_var(t_lexer *lexer, char   **environ);
char    *expantion(char *str, char  **environ);
#endif