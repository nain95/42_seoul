/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:41:05 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/16 19:41:23 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_info *info)
{
	mlx_put_image_to_window(info->mlx,
		info->win, info->img->img, 0, 0);
	ft_draw(info);
	ft_element(info);
	ft_player_draw(info);
	return (0);
}

void	main_loop(t_info *info)
{
	mlx_loop_hook(info->mlx, loop, info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_hook(info->win, 17, 0, close_clean, info);
	mlx_loop(info->mlx);
}

int	mlx_initial(t_info *info)
{
	info->map_row++;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx,
			info->map_col * 64,
			info->map_row * 64, "so_Long");
	info->img->img = mlx_new_image(info->mlx, info->map_col * 64,
			info->map_row * 64);
	info->img->addr = mlx_get_data_addr(info->img->img, &info->img->bpp,
			&info->img->line_l, &info->img->endian);
	init_player_image(info);
	init_wall_image(info);
	init_bottom_image(info);
	init_exit_image(info);
	init_collection_image(info);
	main_loop(info);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 1)
		write(1, "not found file name\n", 20);
	info = init_info();
	if (info == NULL)
		return (-1);
	info->img = init_img();
	if (checker(argv[1], info) == -1)
		return (0);
	mlx_initial(info);
	return (0);
}
