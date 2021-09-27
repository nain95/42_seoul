/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:45:08 by ijeon             #+#    #+#             */
/*   Updated: 2021/09/27 16:05:35 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_split
{
	int		idx;
	int		flag;
	char	*pointer;
}t_split;

char	**ft_split(char const *s, char c);

void	*ft_memset(void *b, int c, size_t len);

char	**get_env(char **envp);
void	exec(char *command, char **envp);

int		redirect_in(const char *file);
int		redirect_out(const char *file);
void	connect_pipe(int pipefd[2], int io);

#endif
