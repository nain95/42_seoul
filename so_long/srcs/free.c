/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:32:04 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/23 01:32:07 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map1(t_info *info)
{
	int	i;

	if (!info->matrix)
		return ;
	i = info->map_row;
	if (i < 0)
	{
		write(1, "ERROR", 5);
		write(1, "map free error\n", 16);
		return ;
	}
	while (i >= 0)
	{
		if (info->matrix[i])
		{
			free(info->matrix[i]);
		}
		i--;
	}
	free(info->matrix);
}

void	free_memory(t_info *info)
{
	/*if (!info)
		exit (0);
	if (info->img)
		free(info->img);
	if (info->matrix)
		free_map1(info);
	if (info->wall)
		free(info->wall);
	if (info->bottom)
		free(info->bottom);
	if (info->exit)
		free(info->exit);
	if (info->collection)
		free(info->collection);
	if (info->player->img)
		free(info->player->img);
	if (info->player)
		free(info->player);
	if (info)
		free(info);*/
	//system("leaks so_long");
	exit (1);
}
