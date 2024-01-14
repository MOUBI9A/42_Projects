/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:13:02 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:15:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_finish_eat(t_philo *philo, bool sign)
{
	pthread_mutex_lock(&philo->p_finish_eat);
	philo->finish_eat = sign;
	pthread_mutex_unlock(&philo->p_finish_eat);
}

void	set_kill(t_data *data, bool sign)
{
	pthread_mutex_lock(&data->p_kill_all);
	data->kill_all = sign;
	pthread_mutex_unlock(&data->p_kill_all);
}

void	set_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_count_eat);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->p_count_eat);
}

void	set_star_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_start_time);
	philo->start_time = gettime();
	pthread_mutex_unlock(&philo->p_start_time);
}

void	set_last_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_last_time);
	philo->last_time = gettime();
	pthread_mutex_unlock(&philo->p_last_time);
}
