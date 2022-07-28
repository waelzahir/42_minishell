/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:45:16 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/28 18:54:01 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

#include "minishell.h"

#include "dtypes.h"

t_token    *get_token(t_tok type, char    *content);
int is_token(char c);

# endif
