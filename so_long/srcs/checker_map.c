/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:13:46 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 19:25:05 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include <stdio.h>
int	checker_map_type(char *file)
{
	int	idx;

	idx = ft_strlen(file);
	if (idx < 4 || file[idx - 1] != 'r' || \
			file[idx - 2] != 'e' || file[idx - 3] != 'b')
		return (-1);
	return (1);
}

int	checker_map(char *file, t_info *info)
{
	int		fd;
	int		gnl_res;
	int		len;
	int		x;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	gnl_res = get_next_line(fd, &line);
	len = ft_strlen(line);
	x = 0;
	while (gnl_res == 1)
	{
		if (ft_strchr(line, 'P'))
		{
			if (info->player->pos_x != -1)
				break;
			info->player->pos_x = x;
			info->player->pos_y = ft_strchr_idx(line, 'P');
		}
		if (ft_strchr(line, ' '))
			break;
		if (len != ft_strlen(line))
			break;
		free(line);
		gnl_res = get_next_line(fd, &line);
		if (gnl_res != 1)
			break;
		x++;
	}
	free(line);
	if (gnl_res == 1)
		write(1, "Error\n", 6);
	return (1);
}
