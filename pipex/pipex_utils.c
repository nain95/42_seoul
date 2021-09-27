/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:02:52 by ijeon             #+#    #+#             */
/*   Updated: 2021/09/27 21:20:00 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			break ;
		i++;
	}
	path = ft_split(&envp[i][5], ':');
	return (path);
}

void	exec(char *command, char **envp)
{
	char	*cmd;
	char	**env;
	char	**chunk;
	char	*error_message;
	int		i;

	i = 0;
	chunk = ft_split(command, ' ');
	env = get_env(envp);
	execve(command, 0, envp);
	while (env[i])
	{
		cmd = ft_strjoin(env[i++], "/");
		cmd = ft_strjoin(cmd, chunk[0]);
		execve(cmd, chunk, envp);
	}
	error_message = ft_strjoin(command, ": command not found\n");
	write(2, error_message, ft_strlen(error_message));
	free(error_message);
	exit(1);
}
