/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:20 by ijeon             #+#    #+#             */
/*   Updated: 2021/11/29 16:18:21 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	int				philo_num;
	int				eat_cnt;
	int				left;
	int				right;
	long			last_eat;
	pthread_t		thread_id;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dieded;
	int				all_ate;
	long			base_time;
	pthread_mutex_t	*thread_id;
	pthread_mutex_t	printing;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
}	t_info;

int		init_info(t_info *info);
void	philo(t_info *info);
t_philo	*init_philo(t_info *info);

int		launcher(t_info *info, t_philo *philo);
void	philo_eats(t_philo *philo);
void	*p_thread(void *void_philo);
void	exit_launcher(t_info *info, t_philo *philos);
void	death_checker(t_info *r, t_philo *p);

int		ft_atoi(const char *str);
int		launcher(t_info *info, t_philo *philo);
long	get_time(void);
void	smart_sleep(long long time, t_info *rules);
void	action_print(t_info *info, int philo_num, char *string);

#endif