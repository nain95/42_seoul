/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:24:04 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 20:58:37 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_char(char c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	else if (65 <= c && c <= 90)
	{
		return (1);
	}
	else if (97 <= c && c <= 122)
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int flag;
	int i;

	flag = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (flag == 0)
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			flag = check_char(str[i]);
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		else
		{
			flag = check_char(str[i]);
		}
	}
	return (str);
}
