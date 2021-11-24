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

void	push_c_list(char *line, t_info *info, int x, int y)
{
	t_collection	*collect;
	t_collection	*temp;

	(info->collection_count)++;
	collect = (t_collection *)malloc(sizeof(t_collection));
	if (!collect)
	{
		free(line);
		free_memory(info);
	}
	collect->pos_x = x;
	collect->pos_y = y;
	if (!info->collection_list->first)
	{
		collect->next = NULL;
		info->collection_list->first = collect;
		return ;
	}
	temp = info->collection_list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = collect;
	collect->next = NULL;
}

void	push_e_list(char *line, t_info *info, int x, int y)
{
	t_exit	*exit;
	t_exit	*temp;

	(info->exit_count)++;
	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
	{
		free(line);
		free_memory(info);
	}
	exit->pos_x = x;
	exit->pos_y = y;
	exit->exit_num = 1;
	if (!info->exit_list->first)
	{
		exit->next = NULL;
		info->exit_list->first = exit;
		return ;
	}
	temp = info->exit_list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = exit;
	exit->next = NULL;
}

int	save_info(char *line, t_info *info, int x, int y)
{
	if (info->player->pos_x != -1)
		return (-1);
	info->player->pos_x = x;
	info->player->pos_y = y;
	return (1);
}

int	save_matrix(t_info *info, int x, char *line)
{
	info->matrix[x] = ft_strdup(line);
	printf("%s\n", info->matrix[x]);
}
