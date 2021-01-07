/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:01:24 by ijeon             #+#    #+#             */
/*   Updated: 2021/01/06 20:35:02 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(char c, char const *to_find)
{
	while (*to_find)
	{
		if (c == *to_find)
			return (1);
		to_find++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		malloc_size;
	int		start_idx;
	int		end_idx;
	char	*new;
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	start_idx = 0;
	end_idx = ft_strlen(s1) - 1;
	while (s1[start_idx] && check(s1[start_idx], set))
		start_idx++;
	while (end_idx >= 0 && check(s1[end_idx], set))
		end_idx--;
	if (!s1[start_idx])
		malloc_size = 1;
	else
		malloc_size = end_idx - start_idx + 2;
	if (!(new = (char *)malloc(malloc_size)))
		return (0);
	tmp = new;
	while (start_idx <= end_idx)
		*tmp++ = s1[start_idx++];
	*tmp = '\0';
	return (new);
}
