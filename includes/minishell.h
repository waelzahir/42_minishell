/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:17:15 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/26 22:17:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include "dtypes.h"
#include "lexer.h"
#include "tokenizer.h"
#include "parser.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


char    **set_env(char    **envp);
char    *get_prompt(void);
void    shell_loop(char *prompt, char   **env);
char    *closing_check(char *str);


# endif