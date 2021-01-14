/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:47:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/13 20:53:31 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		line_split(char **backup, int idx, char **split_line)
{
	char *tmp;
	int len;

	(*backup)[idx] = '\0';
	*split_line = ft_strdup(*backup);
	len = ft_strlen(*backup + idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	tmp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		backup_read(char **backup, int read_size, char **split_line)
{
	int idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (idx = ft_strchr(*backup, '\n')) >= 0)
		return (line_split(backup, idx, split_line));
	else if (*backup)
	{
		*split_line = *backup;
		*backup = 0;
		return (0);
	}
	*split_line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				line_idx;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((line_idx = ft_strchr(backup[fd], '\n')) >= 0)
			return (line_split(&backup[fd], line_idx, line));
	}
	return (backup_read(&backup[fd], read_size, line));
}
