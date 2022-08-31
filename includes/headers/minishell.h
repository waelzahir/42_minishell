/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:49:17 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/31 18:17:49 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "datatypes.h"
# include "lexer.h"
# include "parser.h"
# include "stack.h"
# include "tree.h"
# include "expander.h"
#include "builtins.h"
# include <readline/history.h>
# include <readline/readline.h>
int	exit_stat[4];



char	*get_prompt(void);
char	**init_env();
void     shell(char *prompt);
void    signals(void);
void    executor(t_btree *root, int node, int *fd);
char    *collector(char *s1, char   *s2);
char    **join_cmd(t_token  **tokens);
char    **join_tokens(t_token   **token);
void    single_execute(t_token **token);
int    is_path(char    *s);
char	*path_join(char const *s1, char const *s2, int c);
char	*binary_path(char	*cmd, char	**paths);
char	*get_path(char	*cmd);
void    path_included(char **command, char **redirection, int *fd);
int		ft_fork();
int		is_builtin(char *cmd);
int		exec_built(char **cmd);
// Signals handlers
void	signals_handler();

// Redirections
char    **get_redirection(t_token **token);
int redirect(char   **files);
char    *clean_string(char  *s);
void	remember_redi(int i);

//hered-c
char	*here_doc(char	*str);
int	apply_herdoc(char	*file);
void    exe_launcher(t_btree *root, int mode, int *fd);



#endif