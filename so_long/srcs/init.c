/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:32:46 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/22 23:32:57 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->pos_x = -1;
	player->pos_y = -1;
	return (player);
}

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->player = init_player();
	info->map_row = -1;
	info->map_col = -1;
	info->collection_count = 0;
	info->exit_count = 0;
	info->matrix = NULL;
	info->mlx = NULL;
	info->win = NULL;
	info->img = NULL;
	info->exit_list = (t_exit_list *)malloc(sizeof(t_exit_list));
	info->collection_list = (t_collection_list *) \
							malloc(sizeof(t_collection_list));
	if (!info->collection_list || !info->exit_list)
		return (NULL);
	info->collection_list->first = NULL;
	info->exit_list->first = NULL;
	return (info);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_l = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

void	init_matrix(t_info *info)
{
	info->matrix = (char **)malloc(sizeof(char *) * (info->map_row + 2));
	if (!info->matrix)
		free_memory(info);
	info->matrix[info->map_row + 1] = NULL;
}
