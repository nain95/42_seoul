/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:57:10 by ijeon             #+#    #+#             */
/*   Updated: 2021/12/13 15:57:11 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_atoi(const char *str)
{
	unsigned int		tmp;
	int					answer;
	int					flag;
	char				*s;

	flag = 1;
	tmp = 0;
	s = (char *)str;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\v' || *s == '\r' || *s == '\f')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while ('0' <= *s && *s <= '9')
	{
		tmp *= 10;
		tmp += *s++ - '0';
	}
	answer = tmp * flag;
	return (answer);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(long long time, t_info *rules)
{
	long long	base;

	base = get_time();
	while (!(rules->dieded))
	{
		if (get_time() - base >= time)
			break ;
		usleep(50);
	}
}

void	action_print(t_info *info, int philo_num, char *string)
{
	pthread_mutex_lock(&(info->printing));
	if (!(info->dieded))
	{
		printf("%li ", get_time() - info->base_time);
		printf("%i ", philo_num + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(info->printing));
	return ;
}
