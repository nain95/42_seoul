/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:13:28 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 01:46:22 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lst_tmp;

	lst_tmp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (lst_tmp->next)
	{
		lst_tmp = lst_tmp->next;
	}
	new->next = lst_tmp->next;
	lst_tmp->next = new;
}
