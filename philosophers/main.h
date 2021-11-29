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

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	int			philo_num;
	int			eat_cnt;
	int			left;
	int			right;
	long		last_eat;
	t_info		*info;
}	t_philo;

typedef struct s_info
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_must_eat;
	int			monitor_flag;
	long		base_time;
	long		cur_time;
	t_philo		*philo;
	pthread_t	*thread_id;
	pthread_t	tid_print;
}	t_info;

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
#endif