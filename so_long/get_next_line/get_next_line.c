/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:47:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 16:54:16 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_split(char **backup, int idx, char **split_line)
{
	char	*tmp;
	int		len;

	(*backup)[idx] = '\0';
	*split_line = gnl_strdup(*backup);
	len = gnl_strlen(*backup + idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	tmp = gnl_strdup(*backup + idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	backup_read(char **backup, int read_size, char **split_line)
{
	int	idx;

	if (read_size < 0)
		return (-1);
	if (*backup)
	{
		idx = gnl_strchr(*backup, '\n');
		if (idx >= 0)
			return (line_split(backup, idx, split_line));
	}
	else if (*backup)
	{
		*split_line = *backup;
		*backup = NULL;
		return (0);
	}
	*split_line = gnl_strdup("");
	return (0);
}

char	*malloc_buf(void)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	return (buf);
}

int	get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			*buf;
	int				read_size;
	int				line_idx;

	buf = malloc_buf();
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || buf == NULL )
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = gnl_strjoin(backup[fd], buf);
		line_idx = gnl_strchr(backup[fd], '\n');
		if (line_idx >= 0)
		{
			free(buf);
			return (line_split(&backup[fd], line_idx, line));
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (backup_read(&backup[fd], read_size, line));
}
