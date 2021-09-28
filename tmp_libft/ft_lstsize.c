/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:04:49 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 01:19:16 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int ans;

	ans = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		ans++;
	}
	return (ans);
}
