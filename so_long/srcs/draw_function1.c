/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:26:44 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/23 20:26:48 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_l + (x * (img->bpp / 8)))));
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + (y * img->line_l \
		+ x * (img->bpp / 8))) = color;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_img	*load_image(void *mlx, char *path)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return (img);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
								&img->line_l, &img->endian);
	return (img);
}
