/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:57:44 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/22 23:23:00 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIINS_H
# define BUILTIINS_H

# define EXP_APPEND_MODE 0
# define EXP_ASSIGN_MODE 1
# define FREE 1
# define ALLOCATE 2

int		ft_unset(char **args);
void	unset(char *arg);
int		ft_export(char **args);
int		ft_env(char **env);
int		ft_pwd(int size);
int		ft_cd(char **args);
// Helpers functions for builtins
int		check_identefier(char *id);
char	**remove_pointer(char *arg, char **pointer);
int		size_counter(char **pointer);
char	**arg_to_hash(char *arg);
char	**is_env_var(char *arg);
void	free_2d_table(char **table);
char	**new_env_var(char **var);
char	**edit_env_var(char **var);

#endif