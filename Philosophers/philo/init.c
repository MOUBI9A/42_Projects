/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:11:25 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:12:39 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocation(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philos)
		return (-1);
	return (0);
}

int	data_init(t_data *data, char **argv, int argc)
{
	data->philo_nb = (int) atoi(argv[1]);
	data->death_tm = (long) atoi(argv[2]);
	data->eat_tm = (long) atoi(argv[3]);
	data->sleep_tm = (long) atoi(argv[4]);
	data->kill_all = false;
	data->tm_must_eat = -1;
	if (argc == 6)
		data->tm_must_eat = (int) atoi(argv[5]);
	if (data->philo_nb <= 0 || data->philo_nb > 200 || data->death_tm <= 0
		|| data->eat_tm <= 0 || data->sleep_tm <= 0 || data->tm_must_eat == 0
		|| data->tm_must_eat < -1)
		return (-1);
	return (0);
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->philos[i].forchita_lisra, NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->p_kill_all, NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].forchita_limna = &data->philos[(i + 1)
			% data->philo_nb].forchita_lisra;
		i++;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].data = data;
		data->philos[i].mynb = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].finish_eat = false;
		pthread_mutex_init(&data->philos[i].p_count_eat, NULL);
		pthread_mutex_init(&data->philos[i].p_finish_eat, NULL);
		pthread_mutex_init(&data->philos[i].p_start_time, NULL);
		pthread_mutex_init(&data->philos[i].p_last_time, NULL);
		i++;
	}
}

int	initialisation(t_data *data, char **argv, int argc)
{
	if (data_init(data, argv, argc))
		return (printf("error nb\n"));
	if (allocation(data))
		return (printf("error alloc\n"));
	init_forks(data);
	init_philos(data);
	return (0);
}
