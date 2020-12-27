/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:26:30 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/25 20:46:30 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *destination, const void *source, int num)
{
	const char *tmp;
	char *d;

	d = destination;
	tmp = source;
	while (num--)
		*d++ = *tmp++;	
	return (destination);
}
