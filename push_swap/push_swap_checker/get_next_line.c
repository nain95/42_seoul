/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:47:34 by ijeon             #+#    #+#             */
/*   Updated: 2021/07/02 00:34:06 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int		line_split(char **backup, int idx, char **split_line)
{
	char	*tmp;
	int		len;

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
		*backup = NULL;
		return (0);
	}
	*split_line = ft_strdup("");
	return (0);
}

char	*malloc_buf(void)
{
	char *buf;

	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			*buf;
	int				read_size;
	int				line_idx;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || !(buf = malloc_buf()))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((line_idx = ft_strchr(backup[fd], '\n')) >= 0)
		{
			free(buf);
			return (line_split(&backup[fd], line_idx, line));
		}
	}
	free(buf);
	return (backup_read(&backup[fd], read_size, line));
}
