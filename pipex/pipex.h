/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:45:08 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/04 23:14:36 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);

int		redirect_in(const char *file);
int		redirect_out(const char *file);
void	connect_pipe(int pipefd[2], int io);
char	**get_env(char **envp);
void	exec(char *command, char **envp);

#endif
