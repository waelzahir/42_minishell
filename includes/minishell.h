/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:17:15 by ozahir            #+#    #+#             */
/*   Updated: 2022/07/28 14:24:00 by ozahir           ###   ########.fr       */
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
void	sort_env(char **env);
void    print_toks(char *cmd, char **env);

# endif