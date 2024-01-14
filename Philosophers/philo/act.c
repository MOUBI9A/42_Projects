/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:59:33 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:11:33 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->forchita_limna);
	lock_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->forchita_lisra);
	lock_print(philo, "has taken a fork");
	lock_print(philo, "is eating");
	usleep_custom(philo->data->eat_tm);
	set_last_time(philo);
	set_eat_count(philo);
	if (get_eat_count(philo) == philo->data->tm_must_eat)
		set_finish_eat(philo, true);
	pthread_mutex_unlock(philo->forchita_limna);
	pthread_mutex_unlock(&philo->forchita_lisra);
}

void	think(t_philo *philo)
{
	lock_print(philo, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	lock_print(philo, "is sleeping");
	usleep_custom(philo->data->sleep_tm);
}
