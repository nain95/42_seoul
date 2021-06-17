/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:34:48 by ijeon             #+#    #+#             */
/*   Updated: 2021/06/09 19:49:27 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_CREAT | O_RDWR, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

int main(int argc, const char *argv[])
{
	int i;
	char *cmd1;
	//char cmd2;
	pid_t pid;

	i = argc;
	pid = fork();
	if (pid == -1)
	{
		perror();
		return (-1);
	}
	else if (pid > 0)	//children
	{

	}
	else				//parent
	{

	}
	redirect_in(argv[1]);
	cmd1 = ft_strjoin("/bin/", argv[2]);
	execve(cmd1, STDIN_FILENO, 0);
	redirect_out(argv[2]);
}
