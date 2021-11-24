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

void	other_keys(int key, t_info *info)
{
	if (info->matrix[(int)(info->player->pos_y)][(int)(info->player->pos_x + 1)]
		!= '1' && key == K_D)
	{
		info->player->pos_x += 1;
		//info->moves++;
		//display_moves(info);
	}
	/*if (key == K_ESC)
		close_clean(info);
	if (is_collectible(info, (int)info->player->pos_y,
			(int)info->player->pos_x) == 1)
		set_to_true(info);
	if ((is_exit(info, (int)info->player->pos_y,
				(int)info->player->pos_x) == 1)
		&& c_all_touched(info) == 1)
		close_clean(info);*/
}

int	key_hook(int key, t_info *info)
{
	if (info->matrix[(int)(info->player->pos_y - 1)][(int)(info->player->pos_x)]
		!= '1' && key == K_W)
	{
		info->player->pos_y -= 1;
		//info->moves++;
		//display_moves(info);
	}
	else if (info->matrix[(int)(info->player->pos_y)]
	[(int)(info->player->pos_x - 1)] != '1' && key == K_A)
	{
		info->player->pos_x -= 1;
		//info->moves++;
		//display_moves(info);
	}
	else if (info->matrix[(int)(info->player->pos_y + 1)]
		[(int)(info->player->pos_x)]
		!= '1' && key == K_S)
	{
		info->player->pos_y += 1;
		//info->moves++;
		//display_moves(info);
	}
	other_keys(key, info);
	return (1);
}
