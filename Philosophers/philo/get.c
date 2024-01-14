/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:48 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:11:40 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_finish_eat(t_philo *philo)
{
	bool	sign;

	pthread_mutex_lock(&philo->p_finish_eat);
	sign = philo->finish_eat;
	pthread_mutex_unlock(&philo->p_finish_eat);
	return (sign);
}

bool	get_kill(t_data *data)
{
	bool	sign;

	pthread_mutex_lock(&data->p_kill_all);
	sign = data->kill_all;
	pthread_mutex_unlock(&data->p_kill_all);
	return (sign);
}

int	get_eat_count(t_philo *philo)
{
	int	count_eat;

	pthread_mutex_lock(&philo->p_count_eat);
	count_eat = philo->count_eat;
	pthread_mutex_unlock(&philo->p_count_eat);
	return (count_eat);
}

long	get_star_time(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->p_start_time);
	time = philo->start_time;
	pthread_mutex_unlock(&philo->p_start_time);
	return (time);
}

long	get_last_time(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->p_last_time);
	time = philo->last_time;
	pthread_mutex_unlock(&philo->p_last_time);
	return (time);
}
