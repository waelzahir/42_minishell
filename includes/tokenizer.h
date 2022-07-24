/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:45:16 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/24 15:20:54 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

#include "minishell.h"

#include "dtypes.h"

t_token    *get_token(t_tok type, char    *content);
int is_token(char c);

# endif
