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

t_player	*init_player(void)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	player->pos_x = -1;
	player->pos_y = -1;
	return (player);
}

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->player = init_player();
	return (info);
}

int	main(int argc, char *argv[])
{
	t_info *info;

	info = init_info();
	if (checker_map_type(argv[1]) == -1)
		write(1, "type error\n", 11);
	else if (checker_map(argv[1], info) == -1)
		write(1, "not found file error\n", 22);
	printf("%d, %d", info->player->pos_x, info->player->pos_y);
	system("leaks so_long");
	return (0);
}
