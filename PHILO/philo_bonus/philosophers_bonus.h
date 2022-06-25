/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:40:14 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:55:34 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include<semaphore.h>
# include<signal.h>
# include<fcntl.h>

typedef struct s_data_bonus
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						philo_state;
	long long				start_time;
	sem_t					*print;
	sem_t					*forks;
	sem_t					*finished;
	struct s_philo_bonus	*philo;
}	t_data_bonus;

typedef struct s_philo_bonus
{
	int				id;
	int				pro_start;
	long long		last_meal;
	int				num_of_eats;
	int				finish;
	int				pid;
	pthread_t		thread;
	t_data_bonus	*data;
}	t_philo_bonus;

void		data_init_b(t_data_bonus *philo, char **av, int num);
void		unlocking_forks_b(t_data_bonus *all);
void		locking_forks_b(t_philo_bonus *philo, t_data_bonus *all);
void		ft_print_b(t_philo_bonus *philo, t_data_bonus *all, char *str);
void		sleeping_b(t_philo_bonus *philo, t_data_bonus *all);
void		eating_b(t_philo_bonus *philo, t_data_bonus *all);
void		ft_sleep_b(long time, long start_time);
long long	get_time(void);
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		makeitzero(t_philo_bonus *philo, int num);
void		ft_sem_init(t_data_bonus *all);
void		parsing(int ac, char **av);

#endif