/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:51:48 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/07 01:47:26 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *new;
	t_list *cur;

	if (lst == NULL)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	cur = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur->next = tmp;
		cur = tmp;
		lst = lst->next;
	}
	return (new);
}
