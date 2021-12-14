/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:16:46 by ijeon             #+#    #+#             */
/*   Updated: 2021/12/09 20:16:48 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	philo_eats(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->forks[philo->left]));
	action_print(info, philo->philo_num, "has taken a fork");
	pthread_mutex_lock(&(info->forks[philo->right]));
	action_print(info, philo->philo_num, "has taken a fork");
	pthread_mutex_lock(&(info->meal_check));
	usleep(200);
	action_print(info, philo->philo_num, "is eating");
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(info->meal_check));
	smart_sleep(info->time_to_eat, info);
	philo->eat_cnt++;
	pthread_mutex_unlock(&(info->forks[philo->left]));
	pthread_mutex_unlock(&(info->forks[philo->right]));
}

void	*p_thread(void *void_philo)
{
	int		i;
	t_info	*info;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)void_philo;
	info = philo->info;
	if (philo->philo_num % 2 == 1)
		usleep(15000);
	while (!(info->dieded))
	{
		philo_eats(philo);
		if (info->all_ate)
			break ;
		usleep(200);
		action_print(info, philo->philo_num, "is sleeping");
		usleep(200);
		smart_sleep(info->time_to_sleep, info);
		action_print(info, philo->philo_num, "is thinking");
		usleep(200);
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->number_of_philosophers)
	{
		//pthread_mutex_unlock(&(info->forks[i]));
		//usleep(10);
		pthread_mutex_destroy(&(info->forks[i]));
	}
	i = -1;
	//while (++i < info->number_of_philosophers)
	//	pthread_join(philo[i].thread_id, NULL);
	pthread_mutex_destroy(&(info->printing));
	pthread_mutex_destroy(&(info->meal_check));
	free(philo);
}

void	death_checker(t_info *i, t_philo *p)
{
	int	idx;

	while (!(i->all_ate))
	{
		idx = -1;
		while (++idx < i->number_of_philosophers && !(i->dieded))
		{
			pthread_mutex_lock(&(i->meal_check));
			if (get_time() - p[idx].last_eat > i->time_to_die)
			{
				action_print(i, idx, "died");
				i->dieded = 1;
			}
			pthread_mutex_unlock(&(i->meal_check));
			usleep(100);
		}
		if (i->dieded)
			break ;
		idx = 0;
		while (i->must_eat != -1 && \
		idx < i->number_of_philosophers && p[idx].eat_cnt >= i->must_eat)
			idx++;
		if (idx == i->number_of_philosophers)
			i->all_ate = 1;
	}
}

int	launcher(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->base_time = get_time();
	while (i < info->number_of_philosophers)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, p_thread, &(philo[i])))
			return (1);
		philo[i].last_eat = get_time();
		pthread_detach(philo[i].thread_id);
		i++;
	}
	death_checker(info, philo);
	exit_launcher(info, philo);
	return (0);
}
