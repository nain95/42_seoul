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

int	init_info(t_info *info)
{
	int	i;

	i = -1;
	info->dieded = 0;
	info->all_ate = 0;
	info->forks = (pthread_mutex_t *)malloc \
	(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->forks)
		return (0);
	pthread_mutex_init(&(info->printing), NULL);
	while (++i < info->number_of_philosophers)
		pthread_mutex_init(&(info->forks[i]), NULL);
	pthread_mutex_init(&(info->meal_check), NULL);
	return (1);
}

t_philo	*init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!philo)
		return (NULL);
	while (++i < info->number_of_philosophers)
	{
		philo[i].philo_num = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % info->number_of_philosophers;
		philo[i].last_eat = 0;
		philo[i].info = info;
	}
	return (philo);
}

void	philo(t_info *info)
{
	t_philo	*philo;

	philo = init_philo(info);
	if (!philo)
		return ;
	if (!init_info(info))
		return ;
	launcher(info, philo);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
		write(1, "Wrong arguments\n", 16);
	else
	{
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.time_to_die = ft_atoi(argv[2]);
		info.time_to_eat = ft_atoi(argv[3]);
		info.time_to_sleep = ft_atoi(argv[4]);
		info.must_eat = -1;
		if (argc == 6)
		{
			info.must_eat = ft_atoi(argv[5]);
			if (info.must_eat < 0)
				return (0);
		}
		if (info.number_of_philosophers < 1 || info.time_to_die < 0 || \
		info.time_to_eat < 0 || info.time_to_sleep < 0 || \
		info.number_of_philosophers > 250)
			return (0);
		philo(&info);
	}
	return (0);
}
