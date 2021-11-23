/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:12:25 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/23 20:12:30 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player_image(t_info *info)
{
	info->player->img = load_image(info->mlx,
			"./srcs/textures/wale-64-1.xpm");
	if (!info->player->img.img)
	{
		write(1, "error\n", 7);
        write(1, "player imag error\n", 19);
		free_memory(info);
	}
}

void	init_floor_image(t_info *info)
{
	info->floor = (t_img *)malloc(sizeof(t_img));
	if (!(info->floor))
	{
		write(1, "error\n", 6);
        write(1, "floor imag error\n",18);
		free_memory(info);
	}
	info->floor->img = mlx_xpm_file_to_image(info->mlx,
			"./srcs/textures/greystone.xpm", &(info->floor->width),
			&(info->floor->height));
	info->floor->addr = mlx_get_data_addr(info->floor->img,
			&(info->floor->bpp), &(info->floor->line_l),
			&(info->floor->endian));
}

void	init_wall_image(t_info *info)
{
	info->bottom = (t_img *)malloc(sizeof(t_info));
	if (!(info->bottom))
	{
		write(1, "error\n", 6);
        write(1, "bottom image error\n", 20);
		free_memory(info);
	}
	info->bottom->img = mlx_xpm_file_to_image(info->mlx,
			"./srcs/textures/purplestone.xpm", &info->bottom->width,
			&info->bottom->height);
	info->bottom->addr = mlx_get_data_addr(info->bottom->img,
			&info->bottom->bpp, &info->bottom->line_l,
			&info->bottom->endian);
}

void	init_exit_image(t_info *info)
{
	info->exit_list->img = load_image(info->mlx,
			"./srcs/textures/exit.xpm");
	if (!(info->exit_list->img.img))
	{
		write(1, "error\n", 6);
        write(1, "exit image error\n", 18);
		free_memory(info);
	}
}

void	init_collection_image(t_info *info)
{
	info->collection_list->img = load_image(info->mlx,
			"./srcs/textures/redbrick.xpm");
	if (!(info->collection_list->img.img))
	{
		write(1, "error\n", 6);
        write(1, "collection image error\n", 24);
		free_memory(info);
	}
}

t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	return (img);
}