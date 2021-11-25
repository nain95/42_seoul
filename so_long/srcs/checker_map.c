/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:13:46 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/17 16:10:11 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checker_map_border(int x, char *line, t_info *info)
{
	int	y;

	y = 0;
	if (x == 0 || x == info->map_row)
	{
		while (y < info->map_col)
		{
			if (line[y++] != '1')
				return (-1);
		}
	}
	else
	{
		if (line[0] != '1' || line[info->map_col - 1] != '1')
			return (-1);
	}
	return (1);
}

int	checker_line_elements(int x, char *line, t_info *info)
{
	if (checker_map_border(x, line, info) == -1)
	{
		return (-1);
	}
	if (ft_strchr(line, 'P'))
	{	
		if (save_info(line, info, x, ft_strchr_idx(line, 'P')) == -1)
		{
			return (-1);
		}
	}
	if (ft_strchr(line, 'C'))
		info->collection_count++;
	if (ft_strchr(line, 'E'))
		info->exit_count++;
	return (1);
}

int	checker_map_conditions(char *file, t_info *info)
{
	int		fd;
	int		x;
	char	*line;

	init_matrix(info);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	x = -1;
	while (x++ < info->map_row)
	{
		if (checker_line_elements(x, line, info) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		save_matrix(info, x, line);
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (1);
}

int	checker_map_shape(char *file, t_info *info)
{
	int		fd;
	int		gnl_res;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	gnl_res = get_next_line(fd, &line);
	info->map_col = ft_strlen(line);
	info->map_row++;
	while (gnl_res == 1)
	{
		if (ft_strchr(line, ' ') || info->map_col != ft_strlen(line))
			break ;
		free(line);
		gnl_res = get_next_line(fd, &line);
		if (gnl_res != 1)
			break ;
		info->map_row++;
	}
	free(line);
	close(fd);
	if (gnl_res == 1)
		return (-1);
	return (1);
}

int	checker_map_elements(t_info *info)
{
	if (info->player->pos_x == -1)
		return (-1);
	else if (info->collection_count == 0)
		return (-1);
	else if (info->exit_count == 0)
		return (-1);
	return (1);
}
