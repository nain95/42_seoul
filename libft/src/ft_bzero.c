/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:45:23 by ijeon             #+#    #+#             */
/*   Updated: 2020/12/25 18:02:51 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, int num)
{
        unsigned char *tmp = ptr;
        while (num-- > 0)
                *tmp++ = value;
        return (ptr);
}

void	ft_bzero(void *s, int t)
{
	ft_memset(s, 0, t);
}
