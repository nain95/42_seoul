/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:44:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/28 01:44:28 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char tmp;

	tmp = c;
	if ('0' <= tmp && tmp <= '9')
		return (1);
	return (0);
}
