/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:19:04 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/26 11:19:07 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_on_img(t_img *img, t_img *img2, int x, int y)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < 64)
	{
		draw.y = 0;
		while (draw.y < 64)
		{
			draw.r_x = (float)draw.x / (float)64;
			draw.r_y = (float)draw.y / (float)64;
			draw.pos_x = draw.r_x * img2->width;
			draw.pos_y = draw.r_y * img2->height;
			draw.color = get_pixel(img2, draw.pos_x, draw.pos_y);
			draw.p_data_x = x + draw.x;
			draw.p_data_y = y + draw.y;
			if (draw.color != (int)0xFF000000)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	ft_player_draw(t_info *info)
{
	draw_on_img(info->img, info->player->img,
		(int)info->player->pos_x * 64, (int)info->player->pos_y * 64);
}

void	ft_draw(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->matrix[i])
	{
		j = 0;
		while (info->matrix[i][j])
		{
			if (info->matrix[i][j] == '1')
				draw_on_img(info->img, info->wall, j * 64, i * 64);
			else
				draw_on_img(info->img, info->bottom, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_element_sub(t_info *info, int i, int j)
{
	if (info->matrix[i][j] == '1' || info->matrix[i][j] == '0' \
			|| info->matrix[i][j] == 'P')
		return ;
	if (info->matrix[i][j] == 'C')
	{
		draw_on_img(info->img, info->collection,
			j * 64, i * 64);
	}
	else if (info->matrix[i][j] == 'E')
		draw_on_img(info->img, info->exit,
			j * 64, i * 64);
	else
	{
		write(1, "map_error\n", 10);
		close_clean(info);
	}
}

void	ft_element(t_info *info)
{
	int				i;
	int				j;
	int				x;
	int				y;

	i = 0;
	y = 1;
	while (info->matrix[i])
	{
		x = 1;
		j = 0;
		while (info->matrix[i][j])
		{
			ft_element_sub(info, i, j);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}
