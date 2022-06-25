/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:47:24 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:43:51 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include<semaphore.h>
# include<signal.h>

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_state;
	long long		start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			pro_start;
	long long	last_meal;
	int			finish;
	int			i;
	int			num_of_eats;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

int			ft_atoi(const char *str);
void		data_init(t_data *all, char **av, int num);
void		locking_forks(t_philo *philo);
void		unlocking_forks(t_philo *philo);
long long	get_time(void);
void		ft_sleep(long time, long start_time);
void		sleeping(t_philo *philo);
void		ft_print(t_philo *philo, char *str);
void		eating(t_philo *philo);
void		makeitzero(t_philo *philo, int num);
int			check_all(t_philo *philo, char **av);
int			ft_strlen(const char *s);
int			ft_isdigit(int c);
void		parsing(int ac, char **av);

#endif