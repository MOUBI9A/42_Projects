/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:15:18 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:16:20 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	gettime(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000 + tm.tv_usec / 1000));
}

void	usleep_custom(unsigned long t_to)
{
	long long	start;

	start = gettime();
	while (gettime() - start < (long long)t_to)
		usleep(50);
}

void	lock_print(t_philo *philo, char *str)
{
	if (get_kill(philo->data) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", (gettime() - get_star_time(philo)), philo->mynb, str);
	pthread_mutex_unlock(&philo->data->print);
}
