/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:35:49 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/20 23:35:51 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	save_info(char *line, t_info *info, int x, int y)
{
	if (info->player->pos_x != -1)
		return (-1);
	info->player->pos_x = y;
	info->player->pos_y = x;
	return (1);
}

void	save_matrix(t_info *info, int x, char *line)
{
	info->matrix[x] = ft_strdup(line);
}
