/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:57 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/07 21:35:48 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->mynb % 2 != 1)
	{
		think(philo);
		usleep(100);
	}
	while (1)
	{
		think(philo);
		eating(philo);
		ft_sleep(philo);
	}
	return (NULL);
}

int	check_finish(t_data	*data)
{
	int	i;
	int	all_finish;

	i = 0;
	all_finish = 0;
	while (i < data->philo_nb)
	{
		if (get_finish_eat(&data->philos[i]) == true)
			all_finish++;
		i++;
	}
	return (all_finish);
}

void	monitour(t_data *data)
{
	int	i;
	int	all_finish;

	while (1) 
	{
		i = -1;
		while (++i < data->philo_nb)
		{
			if ((gettime() - get_last_time(&data->philos[i])) >= data->death_tm)
			{
				set_kill(data, true);
				pthread_mutex_lock(&data->print);
				printf("%lld %d died\n", (gettime() 
						- get_star_time(&data->philos[i])), data->philos->mynb);
				break ;
			}
		}
		if (get_kill(data) == true)
			break ;
		all_finish = check_finish(data);
		if (all_finish == data->philo_nb)
			break ;
		else
			all_finish = 0;
	}
}

int	life(t_data *data)
{
	int			i;
	long long	start_time;

	i = 0;
	start_time = gettime();
	while (i < data->philo_nb)
	{
		set_star_time(&data->philos[i]);
		set_last_time(&data->philos[i]);
		pthread_create(&data->philos[i].mythread, NULL, 
			routine, &data->philos[i]);
		usleep(20);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (argc < 5 || argc > 6)
		return (1);
	if (check_input(argv))
		return (1);
	if (initialisation(data, argv, argc))
		return (1);
	if (life(data))
		return (1);
	monitour(data);
	i = 0;
	while (i < data->philo_nb)
	{
		(void) pthread_detach(data->philos[i].mythread);
		i++;
	}
	return (0);
}
