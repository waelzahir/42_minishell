/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:57:44 by sel-kham          #+#    #+#             */
/*   Updated: 2022/08/21 20:52:42 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIINS_H
# define BUILTIINS_H

# define EXP_APPEND_MODE 0
# define EXP_ASSIGN_MODE 1

int	ft_unset(char **args);
int	ft_export(char **args);
int	ft_env(char **env);
int	ft_pwd(int size);
int	ft_cd(char **args);

char	**var_to_hash(char *arg);
int		check_identefier(char *id);

#endif