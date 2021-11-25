/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:59:18 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/24 19:59:20 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_info *info)
{
	if (info->matrix[(int)(info->player->pos_y - 1)][(int)(info->player->pos_x)]
		!= '1' && key == K_W)
		info->player->pos_y -= 1;
	else if (info->matrix[(int)(info->player->pos_y)]
	[(int)(info->player->pos_x - 1)] != '1' && key == K_A)
		info->player->pos_x -= 1;
	else if (info->matrix[(int)(info->player->pos_y + 1)]
		[(int)(info->player->pos_x)]
		!= '1' && key == K_S)
		info->player->pos_y += 1;
	else if (info->matrix[(int)(info->player->pos_y)] \
				[(int)(info->player->pos_x + 1)]
		!= '1' && key == K_D)
		info->player->pos_x += 1;
	else if (key == K_ESC)
		close_clean(info);
	else
		return (1);
	pos_check(info);
	info->moves++;
	ft_putnbr(info->moves);
	write(1, "\n", 1);
	return (0);
}

int	close_clean(t_info *info)
{
	if (info->player->img->img)
		mlx_destroy_image(info->mlx, info->player->img->img);
	if (info->exit->img)
		mlx_destroy_image(info->mlx, info->exit->img);
	if (info->collection->img)
		mlx_destroy_image(info->mlx, info->collection->img);
	if (info->bottom->img)
		mlx_destroy_image(info->mlx, info->bottom->img);
	if (info->wall->img)
		mlx_destroy_image(info->mlx, info->wall->img);
	if (info->img->img)
		mlx_destroy_image(info->mlx, info->img->img);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	//if (info->mlx)
		//free(info->mlx);
	free_memory(info);
	exit (0);
}

void	pos_check(t_info *info)
{
	if (info->matrix[(int)(info->player->pos_y)] \
			[(int)(info->player->pos_x)] == 'C')
	{
		info->matrix[(int)(info->player->pos_y)] \
		[(int)(info->player->pos_x)] = '0';
		info->collection_count--;
	}
	else if (info->matrix[(int)(info->player->pos_y)] \
			[(int)(info->player->pos_x)] == 'E' && \
			info->collection_count == 0)
		close_clean(info);
}
