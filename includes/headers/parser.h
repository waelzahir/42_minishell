/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:50:26 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/28 23:50:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H
int     parse_error(char    *s, t_stack *stack);
int     fill_stacks(t_stack *stack_cmd, t_stack *stack_op, t_lexer  *lexer);
t_btree	*parser(char *str);

#endif