/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:34:48 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/05 19:31:53 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int		redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_CREAT | O_RDWR, 0644);
	if (fd < 0)
	{
		perror(file);
		exit (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

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
	while (env[i])
	{
		cmd = ft_strjoin(env[i++], "/");
		cmd = ft_strjoin(cmd, chunk[0]);
		execve(cmd, chunk, 0);
	}
	error_message = ft_strjoin(command, ": No such command\n");
	write(2, error_message, ft_strlen(error_message));
	free(error_message);
	exit(1);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		status;
	int		pipefd[2];
	pid_t	pid;

	i = argc;
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		redirect_in(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		exec(argv[2], envp);
	}
	else if (pid > 0)
	{
		//waitpid(pid, &status, 0);
		wait(&status);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		exec(argv[3], envp);
	}
}
