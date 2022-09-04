/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:57:44 by sel-kham          #+#    #+#             */
/*   Updated: 2022/09/03 21:23:46 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define EXP_APPEND_MODE 0
# define EXP_ASSIGN_MODE 1
# define FREE 1
# define ALLOCATE 2

int		ft_unset(char **args);
void	unset(char *arg);
int		ft_export(char **args);
int		ft_env(void);
int		ft_pwd(int size);
int		ft_cd(char **args);
int		ft_echo(char **args);
int		ft_exit(char **arg);
// Helpers functions for builtins
int		check_identefier(char *id);
int		size_counter(char **pointer);
char	**arg_to_hash(char *arg);
void	free_2d_table(char **table);
void	print_sorted_array(char **argv);
void	init_env(void);
void	edit_env_var(char *id, char *val);
void	add_env_var(char *id, char *value);
void	append_env_var(char *id, char *value);
char	*get_env_var(char *id);
void	delete_env_var(char *id);

#endif