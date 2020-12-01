/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:03:29 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/01 00:04:47 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		write(1, tmp++, 1);
	}
}
