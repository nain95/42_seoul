/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:44:52 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/28 01:44:28 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	unsigned char tmp;

	tmp = c;
	if (tmp < 'A' || ('Z' < tmp && tmp < 'a') || tmp > 'z')
	{
		return (0);
	}
	return (1);
}
