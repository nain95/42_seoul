/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:24:04 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 15:00:01 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_char(char c)
{
	if (9 <= c && c <= 13)
	{
		return (0);
	}
	else if (32 <= c && c <= 47)
	{
		return (0);
	}
	else if (58 <= c && c <= 64)
	{
		return (0);
	}
	else if (123 <= c && c <= 126)
	{
		return (0);
	}
	return (1);
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
