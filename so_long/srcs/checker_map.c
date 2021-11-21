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

int	checker_map_type(char *file)
{
	int	idx;

	idx = ft_strlen(file);
	if (idx < 4 || file[idx - 1] != 'r' || \
			file[idx - 2] != 'e' || file[idx - 3] != 'b')
		return (-1);
	return (1);
}

char	**checker_map_conditions(char *file, t_info *info)
{
	int		fd;
	int		gnl_res;
	int		x;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	gnl_res = get_next_line(fd, &line);
	x = 0;
	while (x++ < info->map_row)
	{
		if (ft_strchr(line, 'P'))
			if (save_info(line, info, x, ft_strchr_idx(line, 'P')) == -1)
				break ;
		if (ft_strchr(line, 'C'))
			push_c_list(info, x, ft_strchr_idx(line, 'C'));
		free(line);
		gnl_res = get_next_line(fd, &line);
		if (gnl_res != 1)
			break ;
	}
	free(line);
	close(fd);
	if (gnl_res == 1)
		write(1, "Error\n", 6);
	return (1);
}

int	save_info(char *line, t_info *info, int x, int y)
{
	if (info->player->pos_x != -1)
		return (-1);
	info->player->pos_x = x;
	info->player->pos_y = y;
	return (1);
}

int	checker_map_shape(char *file, t_info *info)
{
	int		fd;
	int		gnl_res;
	int		len;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	gnl_res = get_next_line(fd, &line);
	len = ft_strlen(line);
	while (gnl_res == 1)
	{
		if (ft_strchr(line, ' ') || len != ft_strlen(line))
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
		return (print_error("map shape error"));
	return (1);
}

int	checker(char *file, t_info *info)
{
	if (checker_map_shape(file, info) == -1)
		return (-1);
}
