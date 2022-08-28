/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:57:44 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/23 15:29:33 by ozahir           ###   ########.fr       */
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
int		ft_env(void);
int		ft_pwd(int size);
int		ft_cd(char **args);
int	ft_echo(char **args);
// Helpers functions for builtins
int		check_identefier(char *id);
char	**remove_pointer(char *arg, char **pointer);
int		size_counter(char **pointer);
char	**arg_to_hash(char *arg);
char	**is_env_var(char *arg);
void	free_2d_table(char **table);
char	**new_env_var(char **var);
char	**edit_env_var(char **var);
void	print_sorted_array(char **argv);
void	*garbage_collector(int size, int choice);
char	**init_env();


#endif