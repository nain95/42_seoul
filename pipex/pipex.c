/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:34:48 by ijeon             #+#    #+#             */
/*   Updated: 2021/09/27 21:29:50 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in(const char *file)
{
	int	fd;

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

int	redirect_out(const char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
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

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		status;
	int		pipefd[2];
	pid_t	pid;

	i = argc;
	if (argc < 5)
		return (1);
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
		waitpid(pid, &status, WNOWAIT);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		exec(argv[3], envp);
	}
	return (0);
}
