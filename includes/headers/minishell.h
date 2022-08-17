/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:02 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/17 16:40:02 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "datatypes.h"
# include "lexer.h"
# include "parser.h"
# include "t_stack.h"
# include "shell.h"
# include "binary_tree.h"
# include <readline/history.h>
# include <readline/readline.h>

void	print_sorted_array(char **argv);

#endif