/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:10:26 by hel-moue          #+#    #+#             */
/*   Updated: 2023/11/03 12:10:27 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h> 
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philo {
	struct s_data	*data;
	int				mynb;
	pthread_t		mythread;
	int				count_eat;
	pthread_mutex_t	p_count_eat;
	bool			finish_eat;
	pthread_mutex_t	p_finish_eat;
	long			start_time;
	pthread_mutex_t	p_start_time;
	long			last_time;
	pthread_mutex_t	p_last_time;
	pthread_mutex_t	forchita_lisra;
	pthread_mutex_t	*forchita_limna;
}	t_philo;

typedef struct s_data
{
	pthread_t		td;
	t_philo			*philos;
	int				philo_nb;
	int				death_tm;
	int				eat_tm;
	int				sleep_tm;
	int				tm_must_eat;
	bool			kill_all;
	pthread_mutex_t	p_kill_all;
	pthread_mutex_t	print;
	pthread_mutex_t	*frachet;
}	t_data;

int			initialisation(t_data *data, char **argv, int argc);
int			allocation(t_data *data);
void		init_forks(t_data *data);
void		init_philos(t_data *data);
int			data_init(t_data *data, char **argv, int argc);
int			check_input(char **argv);
void		lock_print(t_philo *philo, char *str);
void		usleep_custom(unsigned long t_to);
long long	gettime(void);
// void		ft_exit(t_data *data);
void		eating(t_philo *philo);
void		think(t_philo *philo);
void		ft_sleep(t_philo *philo);
// void		ft_usleep(int time);
void		set_finish_eat(t_philo *philo, bool sign);
bool		get_finish_eat(t_philo *philo);
void		set_kill(t_data *data, bool sign);
bool		get_kill(t_data *data);
void		set_eat_count(t_philo *philo);
int			get_eat_count(t_philo *philo);
void		set_star_time(t_philo *philo);
long		get_star_time(t_philo *philo);
void		set_last_time(t_philo *philo);
long		get_last_time(t_philo *philo);
int			check_finish(t_data	*data);

#endif