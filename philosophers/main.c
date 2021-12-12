/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:13 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/29 16:24:01 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>
#include <sys/time.h>

int	init_info(t_info *info)
{
	int	i;

	i = -1;
	info->cur_time = 0;
	info->monitor_flag = 0;
	info->dieded = 0;
	info->all_ate = 0;
	pthread_mutex_init(&(info->writing), NULL);
	while (++i < info->number_of_philosophers)
		pthread_mutex_init(&(info->forks[i]), NULL);
	pthread_mutex_init(&(info->meal_check), NULL);
	return (1);
}

t_philo	*init_philo(t_info *info)
{
	int	i;
	t_philo *philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!philo)
		return (NULL);
	while (++i < info->number_of_philosophers)
	{
		philo[i].philo_num = i;
		philo[i].last_eat = -1;
		philo[i].left = i;
		philo[i].right = (i + 1) % info->number_of_philosophers;
		philo[i].last_eat = 0;
		philo[i].info = info;
	}
	return (philo);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	philo(t_info *info)
{
	t_philo	*philo;
	int		check;

	philo = init_philo(info);
	if (!philo)
		return ;
	check = init_info(info);
	if (check == -1)
		return ;
	launcher(info, philo);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
		ft_putstr_fd("Wrong arguments\n", 1);
	else
	{
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.time_to_die = ft_atoi(argv[2]);
		info.time_to_eat = ft_atoi(argv[3]);
		info.time_to_sleep = ft_atoi(argv[4]);
		info.number_of_time_must_eat = -1;
		if (argc == 6)
		{
			info.number_of_time_must_eat = ft_atoi(argv[5]);
			if (info.number_of_time_must_eat < 0)
				return (0);
		}
		if (info.number_of_philosophers < 2 || info.time_to_die < 0 || \
		info.time_to_eat < 0 || info.time_to_sleep < 0 || \
		info.number_of_philosophers > 250)
			return (0);
		philo(&info);
	}
	return (0);
}
