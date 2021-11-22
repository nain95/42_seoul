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

char	**checker_map_conditions(char *file, t_info *info)
{
	int		fd;
	int		x;
	char	*line;
	char	**map;

	printf("%d, %d\n", info->map_row, info->map_col);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	get_next_line(fd, &line);
	x = -1;
	while (x++ <= info->map_row)
	{
		if (checker_map_border(x, line, info) == -1)
		{
			free(line);
			close(fd);
			print_error("border error");
			return (NULL);
		}
		if (ft_strchr(line, 'P'))
		{	
			if (save_info(line, info, x, ft_strchr_idx(line, 'P')) == -1)
			{
				print_error("double P");
				free(line);
				close(fd);
				return (NULL);
			}
		}
		if (ft_strchr(line, 'C'))
			push_c_list(info, x, ft_strchr_idx(line, 'C'));
		if (ft_strchr(line, 'E'))
			push_e_list(info, x, ft_strchr_idx(line, 'E'));
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	close(fd);
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
	info->map_col = len;
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
	else if (checker_map_conditions(file, info) == NULL)
		return (-1);
}
