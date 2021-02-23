/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:48:05 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/14 17:55:25 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

int			get_next_line(int fd, char **line);

int			ft_strchr(const char *s, char c);
int			line_split(char **backup, int idx, char **split_line);
int			ft_strlen(const char *str);
int			backup_read(char **backup, int read_size, char **split_line);
char		*malloc_buf(void);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *src);
char		*ft_strcat(char *dest, char *src);
#endif
