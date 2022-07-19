/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:50 by sel-kham          #+#    #+#             */
/*   Updated: 2022/07/19 16:08:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "tokenizer.h"
# include "helpers.h"

void	free_all_pointers(void *ptr);

#endif