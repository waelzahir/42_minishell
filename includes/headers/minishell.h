/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:49:17 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/04 16:58:46 by sel-kham         ###   ########.fr       */
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
# include "builtins.h"
# include <readline/history.h>
# include <readline/readline.h>

int	g_exit_stat[4];

int		get_ret_val(void);
char	*get_prompt(void);
void	shell(char *prompt);
void	signals(void);
void	executor(t_btree *root, int node, int *fd);
char	*collector(char *s1, char *s2);
char	**join_cmd(t_token **tokens);
char	**join_tokens(t_token **token);
void	single_execute(t_token **token);
int		is_path(char *s);
char	*path_join(char const *s1, char const *s2, int c);
char	*binary_path(char	*cmd, char	**paths);
char	*get_path(char	*cmd);
int		ft_fork(void);
int		is_builtin(char *cmd);
int		exec_built(char **cmd);
int		single_exec(t_token **token);
char	*set_path(char *cmd);
void	shell_routine(char	*line, int *fd);
int		closing_check(char *str, int *fd);
char	*get_break_line(char	*str, int *expand);
char	*get_random_name(void);
int		get_random_number(void);
char	*h_clean(char *s);
int		return_function(int pid, int in, int fd);
// Signals handlers
void	signals_handler(void);
void	deflt_signal(void);
void	ignore_signal(void);
void	handl(int sig);
void	handl2(int sig);

// Redirections
char	**get_redirection(t_token **token);
int		redirect(char **files);
char	*clean_string(char *s);
void	remember_redi(int i);

//hered-c
char	*here_doc(char	*str);
int		apply_herdoc(char	*file);
void	exe_launcher(t_btree *root, int mode, int *fd);
void	tokens_free(t_token	**token);
void	memo_p(char **en, int in);

#endif