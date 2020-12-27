/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:28:06 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/27 16:39:04 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int answer;

	answer = 0;
	while (*str++)
		answer++;
	return (answer);
}

char *ft_strchr(char *s, int c)
{
	char *tmp;

	tmp = s;
	if (c == 0)
		return (tmp + ft_strlen(tmp));
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (0);
}
