/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:54:26 by ijeon             #+#    #+#             */
/*   Updated: 2022/01/14 17:54:27 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_list **list)
{
	t_list	*tlist;
	int		i;

	tlist = *list;
	i = 0;
	while (tlist)
	{
		while (((t_ops *)(tlist->content))->args[i])
			free(((t_ops *)(tlist->content))->args[i++]);
		free(((t_ops *)(tlist->content))->args);
		free(((t_ops *)(tlist->content))->operation);
		free(((t_ops *)(tlist->content)));
		free(tlist);
		tlist = tlist->next;
		i = 0;
	}
}

char	*pipe_join(char **s1, char *s2)
{
	size_t	i;
	size_t	l;
	char	*a;

	if (!*s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(*s1));
	a = (char *)malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	i = -1;
	l = 0;
	while ((*s1)[++i])
		a[i] = (*s1)[i];
	while (s2[l])
		a[i++] = s2[l++];
	a[i] = '\0';
	free(*s1);
	return (a);
}
