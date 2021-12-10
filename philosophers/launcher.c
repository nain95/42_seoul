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

void		action_print(t_info *info, int philo_num, char *string)
{
	pthread_mutex_lock(&(info->writing));
	if (!(info->dieded))
	{
		printf("%li ", get_time() - info->base_time);
		printf("%i ", philo_num + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(info->writing));
	return ;
}

void	philo_eats(t_philo *philo)
{
	t_info *info;

	info = philo->info;
	pthread_mutex_lock(&(info->forks[philo->left]));
	action_print(info, philo->philo_num, "has taken a fork");
	pthread_mutex_lock(&(info->forks[philo->right]));
	action_print(info, philo->philo_num, "has taken a fork");
	//pthread_mutex_lock(&(info->meal_check));
	action_print(info, philo->philo_num, "is eating");
	philo->last_eat = get_time();
	//pthread_mutex_unlock(&(info->meal_check));
	//smart_sleep(info->time_eat, rules);
	philo->eat_cnt++;
	pthread_mutex_unlock(&(info->forks[philo->left]));
	pthread_mutex_unlock(&(info->forks[philo->right]));
}

void    *p_thread(void *void_philo)
{
    int			i;
	t_info		*info;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)void_philo;
	info = philo->info;
	if (philo->philo_num % 2)
		usleep(15000);
	while (!(info->dieded))
	{
		philo_eats(philo);
		//if (info->all_ate)
		//	break ;
		action_print(info, philo->philo_num, "is sleeping");
		//smart_sleep(info->time_sleep, info);
		action_print(info, philo->philo_num, "is thinking");
		//break;
		i++;
	}
	return (NULL);
}

int launcher(t_info *info, t_philo *philo)
{
	int				i;

	i = 0;
	info->base_time = get_time();
	while (i < info->number_of_philosophers)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, p_thread, &(philo[i])))
			return (1);
		philo[i].last_eat = get_time();
		i++;
	}
	//death_checker(info, info->philosophers);
	//exit_launcher(info, phi);
	return (0);
}