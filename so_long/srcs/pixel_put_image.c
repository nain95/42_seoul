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
			"./srcs/textures/mario.xpm");
	if (!info->player->img->img)
	{
		write(1, "error\n", 7);
		write(1, "player imag error\n", 19);
		free_memory(info);
	}
}

void	init_bottom_image(t_info *info)
{
	info->bottom = load_image(info->mlx,
			"./srcs/textures/bottom-64.xpm");
	if (!info->bottom)
	{
		write(1, "error\n", 7);
		write(1, "bottom imag error\n", 19);
		free_memory(info);
	}
}

void	init_wall_image(t_info *info)
{
	info->wall = load_image(info->mlx,
			"./srcs/textures/greystone.xpm");
	if (!info->wall)
	{
		write(1, "error\n", 7);
		write(1, "wall imag error\n", 19);
		free_memory(info);
	}
}

void	init_exit_image(t_info *info)
{
	info->exit = load_image(info->mlx,
			"./srcs/textures/exit.xpm");
	if (!(info->exit->img))
	{
		write(1, "error\n", 6);
		write(1, "exit image error\n", 18);
		free_memory(info);
	}
}

void	init_collection_image(t_info *info)
{
	info->collection = load_image(info->mlx,
			"./srcs/textures/item.xpm");
	if (!(info->collection->img))
	{
		write(1, "error\n", 6);
		write(1, "collection image error\n", 24);
		free_memory(info);
	}
}
