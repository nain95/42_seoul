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

void	push_c_list(t_info *info, int x, int y)
{
	t_collection	*collect;
	t_collection	*temp;

	collect = (t_collection *)malloc(sizeof(t_collection));
	//malloc 예외처리
	collect->pos_x = x;
	collect->pos_y = y;
	collect->collection_num = 1;
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

void	push_e_list(t_info *info, int x, int y)
{
	t_exit	*exit;
	t_exit	*temp;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
		free_memory(info);
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