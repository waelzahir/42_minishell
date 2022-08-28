/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:55:33 by ozahir            #+#    #+#             */
/*   Updated: 2022/08/29 00:29:10 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

size_t	ft__strlcpy(char *dst, const char *src, size_t dstsize);
int		ft__strlen(char const *s);
char	*ft__strdup(const char *s1);
char	*ft__strjoin(char *s1, char const *s2);
char	*newline(char *left);
int		nl_sig(char *str);
char	*get_next_line(int fd);
char	*rest(char	*rest);

#endif
